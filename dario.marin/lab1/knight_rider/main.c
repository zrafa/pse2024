#include "utils.h"
int main(void) {

    knight_rider_init();
    unsigned char number_of_frames = 8;
    unsigned char frames[number_of_frames];
    volatile unsigned char *PUERTO_B = (unsigned char *) 0x25;

    frames[0] = 0x0;
    frames[1] = 0x1;
    frames[2] = 0x3;
    for (int i = 3; i < number_of_frames - 1; ++i) {
        frames[i] = frames[i - 1] << 1;
    }
    frames[number_of_frames - 1] = 0x0;

    while (1) {
        for (int i = 0; i < number_of_frames; ++i) {
            *PUERTO_B = frames[i];
            esperar();
        }
        for (int i = number_of_frames - 1; i >= 0; --i) {
            *PUERTO_B = frames[i];
            esperar();
        }
    }
}


