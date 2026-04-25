/*
* Filename: main.c
* Author: [Prince Sherwood]
* Date: [31/03/26]
* Description: My first C Mini Coursework program for UFMFGT-15-1.
*/

#include <stdio.h>
#include <stdlib.h>
#include "io.h"


int main(){

    WaveformSample *data =NULL;

    int n = load_data("power_quality_log.csv",&data);

    if (n<=0) {
        return 1;
    }

    printf("loaded %d samples\n",n);

    free(data);
    return 0;
}
