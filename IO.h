#ifndef IO_H
#define IO_H
#include "waveform.h"

WaveformSample *load_csv(const char *filename, int *count);

void write_results(const char *filename, PhaseResult[3]);

#endif