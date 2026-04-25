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

    printf("Step 1:Looking for :%s\n",input_file);
    fflush(stdout);

    int sample_count = 0;
    WaveformSample *samples = load_csv(input_file, &sample_count);

    if (samples == NULL) {
        printf("Step 1 Failed:Cant Load CSV\n");
        fflush(stdout);
        getchar();
        return 1;
    }

    printf("Step 2:Loaded %d samples from '%s'\n", sample_count, input_file);
    fflush(stdout);

    printf("debug-first sample: timestamp=%.4f, PhaseA=%.4f\n",
           samples[0].timestamp, samples[0].phase_A_voltage);
    fflush(stdout);


    PhaseResult results[3];
    analyse_all_phases(samples, sample_count, results);

    printf("Step 3: Completed Analysis\n");
    fflush(stdout);

    write_results(output_file, results);

    printf("Step 4:Done! Check results.txt\n");
    fflush(stdout);


    free(samples);
    samples = NULL;

    getchar();
    return 0;

}