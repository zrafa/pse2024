#include "wav_file.h"


wav_file_t* wav_open(char *path)
{
	wav_file_t *wf;
	size_t is_read;
	size_t path_size;

	wf = (wav_file_t*) malloc(sizeof(wav_file_t));
	if (!wf) {
		perror("Error allocating memory for WAV file handler");
		return NULL;
	}

	wf->header = (wav_header_t*) malloc(sizeof(wav_header_t));
	if (!wf) {
		perror("Error allocating memory for WAV header");
		free(wf);
		return NULL;
	}

	wf->file = fopen(path, "rb");
	if (!wf->file) {
		perror("Error opening WAV file");
		free(wf->header);
		free(wf);
		return NULL;
	}

	is_read = fread(wf->header, sizeof(wav_header_t), 1, wf->file);
	if (is_read != 1) {
		perror("Error reading WAV header");
		fclose(wf->file);
		free(wf->header);
		free(wf);
		return NULL;
	}

	if (memcmp((char*) wf->header->chunk_id, "RIFF", 4) != 0
		|| memcmp((char*) wf->header->format, "WAVE", 4) != 0) {
		perror("File is not WAV file");
		fclose(wf->file);
		free(wf->header);
		free(wf);
		return NULL;
	}

	path_size = strlen(path) + 1;
	wf->path = (char*) malloc(path_size);
	memcpy(wf->path, path, path_size);
	wf->samples = NULL;

	return wf;
}

void wav_close(wav_file_t *wf)
{
	if (!wf)
		return;

	fclose(wf->file);
	free(wf->header);
	free(wf->path);
	if (wf->samples)
		free(wf->samples);
	free(wf);
}

uint8_t* wav_samples(wav_file_t *wf)
{
	size_t bytes_read;

	if (!wf)
		return NULL;

	if (wf->samples)
		return wf->samples;

	// Asignar memoria para el búfer de datos basado en header.subchunk2_size
	wf->samples = (uint8_t*) malloc(wf->header->subchunk2_size);
	if (!wf->samples) {
		perror("Error allocating memory for WAV data buffer");
		return NULL;
	}

	// Leer los datos de audio en el búfer
	bytes_read = fread(wf->samples, 1, wf->header->subchunk2_size, wf->file);
	if (bytes_read != wf->header->subchunk2_size) {
		perror("Error reading audio data");
		return NULL;
	}

	return wf->samples;
}

void wav_print_info(wav_file_t *wf)
{
	if (!wf)
		return;

	printf(
		"Chunk ID:           %.4s\n"
		"Chunk Size:         %i\n"
		"Format:             %.4s\n"
		"Subchunk1 ID:       %.4s\n"
		"Subchunk1 Size:     %i\n"
		"Audio Format:       %i\n"
		"Number of Channels: %i\n"
		"Sample Rate:        %i\n"
		"Byte Rate:          %i bytes/s\n"
		"Block Align:        %i\n"
		"Bits per Sample:    %i\n"
		"Subchunk2 ID:       %.4s\n"
		"Subchunk2 Size:     %i\n",
		wf->header->chunk_id,
		wf->header->chunk_size,
		wf->header->format,
		wf->header->subchunk1_id,
		wf->header->subchunk1_size,
		wf->header->audio_format,
		wf->header->num_channels,
		wf->header->sample_rate,
		wf->header->byte_rate,
		wf->header->block_align,
		wf->header->bits_per_sample,
		wf->header->subchunk2_id,
		wf->header->subchunk2_size
	);
}
