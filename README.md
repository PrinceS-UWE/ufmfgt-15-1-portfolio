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
| File           | Purpose                                             |
|----------------|-----------------------------------------------------|
| main.c         | Entry point, handles arguments and program flow     |
| waveform.c/.h  | Voltage analysis function                           |
| IO.c/.h        | CSV loading and writes the results to the text file |
| CMakeLists.txt | Build Configuration                                 |
| README.md      | This file                                           |

##How to run Program from Github

- Clone Repository from github link(On github repository page, click 
code then clone using URL or Github integration)
- Open CLion
- Go to File > Open > Choose the cloned folder
- Copy the power_quality_log.csv file to the cmake-build-debug folder
- Set the program arguments > Run > Edit configuration , 
change program argument to power_quality_log.csv
- Set working directory to your cmake-build-debug folder e.g C: \Users \username 
\CLionProjects \program folder \cmake-build-debug and click Ok
- Click run button , output will be shown on console and results will be written to
results.txt in cmake-build-debug 

##How to run Program from ZipFile
- Download zip file from repository
- Extract the file to desired location
- Open CLion 
- Go to File > Open > Select extracted Folder
- Set Program Arguments > Run > Edit Configuration
- Set program argument to power_quality_log.csv
- Set working directory to your cmake-build-debug folder
-  Click run button , output will be shown on console and results will be written to
   results.txt in cmake-build-debug

github: https://github.com/PrinceS-UWE/ufmfgt-15-1-portfolio
##How to run Program from Github

- Clone Repository from github link(On github repository page, click 
code then clone using URL or Github integration)
- Open CLion
- Go to File > Open > Choose the cloned folder
- Copy the power_quality_log.csv file to the cmake-build-debug folder
- Set the program arguments > Run > Edit configuration , 
change program argument to power_quality_log.csv
- Set working directory to your cmake-build-debug folder e.g C: \Users \username 
\CLionProjects \program folder \cmake-build-debug and click Ok
- Click run button , output will be shown on console and results will be written to
results.txt in cmake-build-debug 

##How to run Program from ZipFile
- Download zip file from repository
- Extract the file to desired location
- Open CLion 
- Go to File > Open > Select extracted Folder
- Set Program Arguments > Run > Edit Configuration
- Set program argument to power_quality_log.csv
- Set working directory to your cmake-build-debug folder
-  Click run button , output will be shown on console and results will be written to
   results.txt in cmake-build-debug

github: https://github.com/PrinceS-UWE/ufmfgt-15-1-portfolio