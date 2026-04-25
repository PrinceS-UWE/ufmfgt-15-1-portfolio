#include <math.h>
#include "waveform.h"

double compute_rms(double*values,int n){
    double sum= 0.0;

    for (int i=0;i<n;i++){
        sum+=values[i]*values[i];
    }
    return sqrt(sum/n);
}