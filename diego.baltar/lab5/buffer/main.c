/**
 * @file main.c
 * @author Diego Pablo Matías Baltar <diego.baltar@est.fi.uncoma.edu.ar>
 * @brief Lector de archivos WAV
 * @date 2024-06-26
 *
 * Programa para enviar datos de audio WAV al puerto serial.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include "wav_file.h"


#define SERIAL_PORT "/dev/ttyUSB0"
#define SERIAL_BAUD_RATE B9600


int serial_init()
{
	int serial_port;
	struct termios tty;

	// Abrir puerto serial
	serial_port = open(SERIAL_PORT, O_RDWR | O_NOCTTY | O_SYNC);
	if (serial_port < 0) {
		perror("Error opening serial port");
		return -1;
	}

	// Configurar el puerto serial
	if (tcgetattr(serial_port, &tty) != 0) {
		perror("Error getting tty attributes");
		close(serial_port);
		return -1;
	}

	cfsetospeed(&tty, SERIAL_BAUD_RATE);
	cfsetispeed(&tty, SERIAL_BAUD_RATE);

	tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;
	tty.c_iflag &= ~IGNBRK;
	tty.c_lflag = 0;
	tty.c_oflag = 0;
	tty.c_cc[VMIN]  = 1;
	tty.c_cc[VTIME] = 5;
	tty.c_iflag &= ~(IXON | IXOFF | IXANY);
	tty.c_cflag |= (CLOCAL | CREAD);
	tty.c_cflag &= ~(PARENB | PARODD);
	tty.c_cflag &= ~CSTOPB;
	tty.c_cflag &= ~CRTSCTS;

	if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
		perror("Error setting tty attributes");
		close(serial_port);
		return -1;
	}

	return serial_port;
}

int main(int argc, char **argv)
{
	wav_file_t *wf;
	uint8_t *samples;
	char *path;
	int serial_port;
	size_t total_bytes_written;
	ssize_t bytes_written;

	if (argc < 2) {
		printf("No se especifica archivo WAV\n");
		return EXIT_FAILURE;
	}

	path = argv[1];
	wf = wav_open(path);
	if (!wf) {
		printf("No se pudo abrir archivo WAV '%s'\n", path);
		return EXIT_FAILURE;
	}

	wav_print_info(wf);
	samples = wav_samples(wf);
	serial_port = serial_init();

	//printf("\nSerial port FD: %i\n", serial_port);
	printf("\nSending samples to serial port \"%s\"...\n", SERIAL_PORT);

	// Enviar datos al puerto serial
	total_bytes_written = 0;
	while (total_bytes_written < wf->header->subchunk2_size) {
		bytes_written = write(serial_port, samples + total_bytes_written,
							  wf->header->subchunk2_size - total_bytes_written);
		if (bytes_written < 0) {
			perror("Error writing to serial port");
			close(serial_port);
			wav_close(wf);
			return EXIT_FAILURE;
		}

		total_bytes_written += bytes_written;
	}

	printf("\n%i bytes sent.\n", wf->header->subchunk2_size);
	close(serial_port);
	wav_close(wf);

	return EXIT_SUCCESS;
}
