/**********************************************************************
 *
 * wav_file.c - Utilidad para leer datos de un archivo WAV
 *
 **********************************************************************/

#ifndef _WAV_FILE_
#define _WAV_FILE_


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


/* WAV header */
typedef struct
{
	uint8_t  chunk_id[4];     /* "RIFF" */
	uint32_t chunk_size;      /* Size of the overall file - 8 bytes */
	uint8_t  format[4];       /* "WAVE" */

	uint8_t  subchunk1_id[4]; /* "fmt " */
	uint32_t subchunk1_size;  /* Size of the fmt chunk */
	uint16_t audio_format;    /* Audio format (PCM = 1) */
	uint16_t num_channels;    /* Number of channels */
	uint32_t sample_rate;     /* Sample rate */
	uint32_t byte_rate;       /* (Sample Rate * BitsPerSample * Channels) / 8 */
	uint16_t block_align;     /* (BitsPerSample * Channels) / 8 */
	uint16_t bits_per_sample; /* Bits per sample */

	uint8_t  subchunk2_id[4]; /* "data" */
	uint32_t subchunk2_size;  /* Size of the data chunk */

} wav_header_t;

/* WAV file handler */
typedef struct
{
	char *path;
	FILE *file;
	wav_header_t *header;
	uint8_t *samples;
} wav_file_t;


wav_file_t* wav_open(char *path);
void wav_close(wav_file_t *wav_file);
uint8_t* wav_samples(wav_file_t *wav_file);
void wav_print_info(wav_file_t *wav_file);


#endif /* _WAV_FILE_ */
