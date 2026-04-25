/*
* Filename: main.c
* Author: [Prince Sherwood]
* Date: [31/03/26]
* Description: My first C Mini Coursework program for UFMFGT-15-1.
*/

#include <stdio.h>
#include <stdlib.h>
#include "IO.h"
#include "waveform.h"

int main(int argc, char *argv[]) {


    if (argc < 2) {
        fprintf(stderr, "Usage: %s < power_quality_log.csv>\n", argv[0]);
        return 1;
    }

    const char *input_file  = argv[1];
    const char *output_file = "results.txt";


    int sample_count = 0;
    WaveformSample *samples = load_csv(input_file, &sample_count);

    if (samples == NULL) {
        return 1;
    }

    printf("Loaded %d samples from '%s'\n", sample_count, input_file);

    PhaseResult results[3];
    analyse_all_phases(samples, sample_count, results);

    write_results(output_file, results);

    printf("Done! Check results.txt\n");

    free(samples);
    samples = NULL;

    return 0;

}