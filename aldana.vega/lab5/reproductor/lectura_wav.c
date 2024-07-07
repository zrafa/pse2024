#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <time.h>
#include <sys/select.h>

typedef struct
{
    char riff[4];
    uint32_t file_length;
    char wave[4];
    char fmt[4];
    uint32_t fmt_length;
    uint16_t format_tag;
    uint16_t channels;
    uint32_t sample_rate;
    uint32_t bytes_per_second;
    uint16_t block_align;
    uint16_t bits_per_sample;
    char data[4];
    uint32_t data_length;

}volatile wav;

wav wav_header;
int serial_port;

#define CRTSCTS  020000000000

int configure_port(int fd) {
    struct termios tty;

    if (tcgetattr(fd, &tty) != 0) {
        perror("tcgetattr");
        return -1;
    }

    cfsetospeed(&tty, B9600);
    cfsetispeed(&tty, B9600);

    tty.c_cflag &= ~PARENB; // Sin paridad
    tty.c_cflag &= ~CSTOPB; // 1 bit de parada
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8; // 8 bits de datos

    tty.c_cflag &= ~CRTSCTS; // Sin control de flujo
    tty.c_cflag |= CREAD | CLOCAL; // Habilitar lectura, ignorar control de línea

    tty.c_lflag &= ~ICANON;
    tty.c_lflag &= ~ECHO; // Deshabilitar eco
    tty.c_lflag &= ~ECHOE;
    tty.c_lflag &= ~ISIG; // Deshabilitar señales

    tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Deshabilitar control de flujo por software
    tty.c_iflag &= ~(ICRNL | INLCR); // Sin conversión de retorno de carro/nueva línea

    tty.c_oflag &= ~OPOST; // Deshabilitar procesamiento de salida

    if (tcsetattr(fd, TCSANOW, &tty) != 0) {
        perror("tcsetattr");
        return -1;
    }

    return 0;
}

int main(int argc, char  *argv[]){
    //Abrir archivo wav
    if(argc < 2){
        printf("Sin archivo");
        return 1;
    }

    FILE *fp = fopen(argv[1],"rb");
    if(!fp){
        printf("Error al abrir el archivo");
        return 1;
    }

    fread(&wav_header,sizeof(wav_header),1,fp);
    print_cabecera();

    // Abrir puerto serial
    serial_port = open("/dev/ttyUSB0", O_WRONLY);

    if (serial_port < 0) {
        perror("open");
        return -1;
    }

    if (configure_port(serial_port) != 0) {
        close(serial_port);
        return -1;
    }

    //Leer archivo wav
    wav_read(fp);

    close(serial_port);
    fclose(argv[1]);
}

//Lee byte a byte y lo envia por el serial
void wav_read(FILE *fp){
    int numMuestras = wav_header.data_length/(wav_header.bits_per_sample/8);
    uint8_t muestra;
    for(int i = 0; i < numMuestras; i++){
        fseek(fp,sizeof(wav_header)+i*sizeof(uint8_t),SEEK_SET);
        fread(&muestra,sizeof(uint8_t),1,fp);
        printf("muestra: %X\n",muestra);
        write(serial_port,muestra,1);
    }
    fseek(fp,0,SEEK_SET);
    
}

void print_cabecera(){
    printf("ID:%s\n", wav_header.riff);
    printf("Tamaño del archivo: %d bytes\n",wav_header.file_length);
    printf("Formato:%s\n",wav_header.wave);
    printf("%s\n",wav_header.fmt);
    printf("Formato tamaño:%d\n",wav_header.fmt_length);
    printf("Formato tag:%d\n",wav_header.format_tag);
    printf("Canales: %d\n",wav_header.channels);
    printf("Sample rate: %d\n",wav_header.sample_rate);
    printf("Bytes por segundo: %d\n",wav_header.bytes_per_second);
    printf("Bloque alineacion: %d\n",wav_header.block_align);
    printf("Bits per sample: %d\n",wav_header.bits_per_sample);
    printf("Data: %s\n",wav_header.data);
    printf("Data tamaño: %d\n",wav_header.data_length);
}