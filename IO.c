#include <stdio.h>
#include <stdlib.h>
#include "waveform.h"
#include "io.h"



int load_data(const char *power_quality_log,WaveformSample **data){
    FILE *file=fopen(power_quality_log,"r");
    if (!file){
        printf("Error:File not found\n");
        return-1;
    }
    int count=0;
    char line[256];

    fgets(line,sizeof(line),file);

    while (fgets(line,sizeof(line),file)){
        count++;
    }

    rewind(file);
    fgets(line,sizeof(line),file);

    *data= (WaveformSample*)malloc(count*
            sizeof(WaveformSample));

    for (int i=0;i<count;i++){
        fscanf(file,"%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
               &(*data)[i].timestamp,
               &(*data)[i].phase_A_voltage,
               &(*data)[i].phase_B_voltage,
               &(*data)[i].phase_C_voltage,
               &(*data)[i].line_current,
               &(*data)[i].frequency,
               &(*data)[i].power_factor,
               &(*data)[i].thd_percent);
    }

    printf("Trying to open:%s\n",power_quality_log);

    fclose(file);
    return count;
}
