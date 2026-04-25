#include "IO.h"
#include <stdio.h>
#include <stdlib.h>


/*
   loading the CSV
   Opens the file
   Counts the number of data rows
   Back to the start
   Skip the header line
 */
WaveformSample *load_csv(const char *filename, int *count) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return NULL;
    }

    char line[512];
    int rows = 0;

    fgets(line, sizeof(line), fp);  /* skip the header line */
    while (fgets(line, sizeof(line), fp) != NULL) {
        rows++;
    }

    if (rows == 0) {
        fprintf(stderr, "Error: file '%s' contains no data rows\n", filename);
        fclose(fp);
        return NULL;
    }

    WaveformSample *samples = malloc(rows * sizeof(WaveformSample));
    if (samples == NULL) {
        fprintf(stderr, "Error: malloc failed - not enough memory\n");
        fclose(fp);
        return NULL;
    }


    rewind(fp);
    fgets(line, sizeof(line), fp);  /* skip header again */

    int i = 0;

    WaveformSample *ptr = samples;

    while (i < rows && fgets(line, sizeof(line), fp) != NULL) {
        int parsed = sscanf(line,
                            "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
                            &ptr->timestamp,
                            &ptr->phase_A_voltage,
                            &ptr->phase_B_voltage,
                            &ptr->phase_C_voltage,
                            &ptr->line_current,
                            &ptr->frequency,
                            &ptr->power_factor,
                            &ptr->thd_percent);
        if (parsed != 8) {
            fprintf(stderr, "Warning: row %d has only %d fields - skipping\n", i + 1, parsed);
        } else {
            ptr++;
            i++;
        }
    }

    fclose(fp);
    *count = i;
    return samples;
}

/*
   write_results
   Writes a plain-text report to the given filename.
 */
void write_results(const char *filename, PhaseResult results[3]) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not write to '%s'\n", filename);
        return;
    }

    const char *phase_names[] = {"Phase A", "Phase B", "Phase C"};

    fprintf(fp, "===========================================\n");
    fprintf(fp, "  POWER QUALITY ANALYSIS REPORT\n");
    fprintf(fp, "===========================================\n\n");

    for (int i = 0; i < 3; i++) {
        fprintf(fp, "--- %s ---\n", phase_names[i]);
        fprintf(fp, "  RMS Voltage    : %.4f V\n", results[i].rms_voltage);
        fprintf(fp, "  Peak-to-Peak   : %.4f V\n", results[i].peak_to_peak);
        fprintf(fp, "  DC Offset      : %.6f V\n", results[i].dc_offset);
        fprintf(fp, "  Clipping events: %d samples\n", results[i].clipping_count);
        fprintf(fp, "  Tolerance      : %s\n",
                results[i].in_tolerance ? "PASS (within +-10%% of 230V)"
                                        : "FAIL (outside +-10%% of 230V)");
        fprintf(fp, "\n");
    }

    fprintf(fp, "===========================================\n");
    fclose(fp);

    printf("Results written to '%s'\n", filename);
}