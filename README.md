# Power Quality Waveform Analyser 
**Author:**Prince Sherwood
*Module:**UFMFGT-15-1 Programming for Engineers
**Language:**C (C99)

##What does this do ?
Reads a CSV file of 1000 power grid samples and calculates:
- RMS voltage per phase 
- DC offset per phase 
- Clipping Detection (Voltage has to be >=324.9V)
- Tolerance Check (Range of +-10% of 230V nominal)

The results are then put into a txt file called Results.txt

##File Structure
| File          | Purpose |
|---------------|---|
| main.c        | Entry point, handles arguments and program flow
| waveform.c/.h | Voltage analysis function|
|IO.c/.h | CSV loading and writes the results to the text file|
|CMakeLists.txt | Build Configuration |
|README.md | This file |

