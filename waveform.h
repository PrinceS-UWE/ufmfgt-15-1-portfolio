#ifndef WAVEFORM_H
#define WAVEFORM_H

/*Waveform file holds all the fields from the csv file
 Typedef groups the variables together under a single name WaveformSample
 */
typedef struct {
    double timestamp;
    double phase_A_voltage;
    double phase_B_voltage;
    double phase_C_voltage;
    double line_current;
    double frequency ;
    double power_factor;
    double thd_percent;
}WaveformSample;

typedef struct{
    double rms_voltage;
    double peak_to_peak;
    double dc_offset;
    int    clipping_count;
    int    in_tolerance;
} PhaseResult;

/*calculating the RMS voltage for phase 1
 samples points to the array in the waveform sample
 n is the amount of samples
 */
double compute_rms(WaveformSample *samples, int n, int field);
double compute_peak_to_peak(WaveformSample *samples, int n, int field);
double compute_dc_offset(WaveformSample *samples, int n, int field);
int check_tolerance(double rms);
void analyse_all_phases(WaveformSample *samples, int n, PhaseResult results[3]);
double get_phase_voltage(WaveformSample *sample, int field);

#endif
