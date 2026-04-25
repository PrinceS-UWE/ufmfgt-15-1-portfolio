#include <math.h>
#include <float.h>
#include "waveform.h"

double get_phase_voltage(WaveformSample *samples,int field){
    if (field == 0) return samples->phase_A_voltage;
    if (field == 1) return samples->phase_B_voltage;
    return samples->phase_C_voltage;
}

double compute_rms(WaveformSample *samples, int n, int field){
    double sum_sq=0.0;
    for (int i=0; i<n ;i++){
        double v= get_phase_voltage(samples + i, field);
        sum_sq += v*v;
    }
    return sqrt(sum_sq/n);
}

double compute_peak_to_peak(WaveformSample *samples, int n, int field) {
    double max_v = -DBL_MAX;
    double min_v = DBL_MAX;

    for (int i = 0; i < n; i++) {
        double v = get_phase_voltage(samples + i, field);
        if (v > max_v) max_v = v;
        if (v < min_v) min_v = v;
    }
    return max_v - min_v;

}
double compute_dc_offset(WaveformSample *samples, int n , int field){
    double sum =0.0;
    for (int i = 0;i<n;i++){
        sum +=get_phase_voltage(samples + i, field);
    }
    return sum /n;
}

int detect_clipping(WaveformSample *samples, int n , int field){
    int count = 0;
    WaveformSample *ptr = samples;
    WaveformSample *end = samples + n;

    while (ptr <end){
        double v= get_phase_voltage(ptr, field);
        if (v>= 324.9 || v <=-324.9){
            count++;
        }
        ptr++;
    }
    return count;
}
int check_tolerance(double rms){
    double lower = 230.0 *0.90;
    double upper = 230.0 * 1.10;
    return (rms >=lower && rms <= upper)?1:0;
}

void analyse_all_phases(WaveformSample *samples, int n, PhaseResult results[3]){
    for (int phase = 0; phase <3; phase++){
        results[phase].rms_voltage = compute_rms(samples, n, phase);
        results[phase].peak_to_peak = compute_peak_to_peak(samples, n, phase);
        results[phase].dc_offset = compute_dc_offset(samples, n, phase);
        results[phase].clipping_count = detect_clipping(samples, n, phase);
        results[phase].in_tolerance = check_tolerance(results[phase].rms_voltage);
    }
}
