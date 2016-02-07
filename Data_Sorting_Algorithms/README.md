Citation - This assignment is from a course at California State University, Chico. Thereby, all credits for assignment instructions and program problem statement should be given to the cited personnel or organization. http://www.ecst.csuchico.edu/~judyc/1516F-csci311/assignments/program2-sorting.html Professor Judith Challinger, California State University, Chico



Project - This programming assignment needs you to implement different sorting algorithms using C++ like, merge sort, insertion sort and randomized quick sort.


This assignment is both an exercise in implementing some of the sorting algorithms we have been discussing, and an opportunity to conduct some timing tests in order to gather empirical data about the amount of time different sorts take on different amounts of data.




The Program

This program sorts population data. The program expects a file of comma separated values, one line per city, of the following form:

<city>,<state>,<population>

For example, a small file containing population data on three cities might look like:

Vina,California,237
San Francisco,California,812826
Santa Fe,New Mexico,68642

Notice how there are no spaces around the commas, and no commas in the numbers! The comma is used to separate the fields. The program output for just one of the sorts - insertion sort - for the file above, looks like this: 



The main, drivers, timing functions, reading of the census data file, and initialization of the CensusData object, are all provided for you in the following files. You will be able to compile and execute without any changes, but the data will not be sorted of course.

CensusData.h
CensusData.cpp
CensusDataSorts.cpp
CensusSort.cpp
makefile

Class CensusData stores the census data in a vector and provides several different sorting functions. The data may be sorted by population value or by city name. Your job is to write the following functions that will sort the census data, by either population or city name:

CensusData::insertionSort( )
CensusData::mergeSort( )
CensusData::quickSort( )
You may also declare and implement private helper functions for each sort as needed. You may edit CensusData.h below where the comments indicate. All of the code you implement will go in CensusDataSorts.cpp. Neither of the other two files may be modified.

Several files are provided to use as input data, obtained from from http://www.census.gov/popest/data/cities/totals/2011/index.html. The files are of varying sizes. There are duplicates as each population area is represented twice. Once you have implemented and tested the sort functions, you will run a series of test on files of different sizes and collect and graph the timing data. Be sure to examine the output to check for correct sorting. The input files are:

CENSUS2010POP-Alabama-Alabama.csv - 1,102 records
CENSUS2010POP-Alabama-California.csv - 3,920 records
CENSUS2010POP-Alabama-Idaho.csv - 7,932 records
CENSUS2010POP-Alabama-Iowa.csv - 21,236 records
CENSUS2010POP-Alabama-Missouri.csv - 41,712 records
CENSUS2010POP.csv - 81,746 records
After downloading all of the files...

compile and link with make
run using csort 3cities.csv
You will probably want to redirect the output to a file using the redirection operator >. Some of the runs may take long enough that your remote connection to jaguar will time out due to inactivity. If this happens, run it in the background.


After you implement your sort functions, and have determined that they sort the data correctly, run csort on each of the provided census files. For each type of sort, and each sorting target (population or city), collect timing information for 5 separate runs on each input file. Use the smallest of the 5 values to plot one point in a graph. You will create 6 graphs, each will have the number of records along the x-axis, and the time taken on the y-axis:

insertion sort by population
insertion sort by city name
merge sort by population
merge sort by city name
quicksort by population
quicksort by city name
Create a project report in a pdf that contains tables that show ALL of the timing data from every run. Highlight the smallest number from each run that was used when graphing the times. Include the six graphs described above. Include a narrative discussion of what conclusions you can draw from your results. Name your report using your last name-first name, as in Challinger-Judy.pdf.

Additional Requirements:

Your program must compile and execute on jaguar using -std=c++11 -Wall -W -Werror -pedantic
Implement the randomized version of the quicksort algorithm as described in Chapter 7.3 of Cormen. Use std::default_random_engine, and be sure to seed it.
Follow the pseudocode given in Cormen - use close to the same function names, and pass the same arguments (except for the array itself).
Make sure that you run all of your timing tests on the same machine.
Be sure to document your part of the code and be consistent with style, naming, indentation, etc.
Your report must be entirely in ONE pdf document.
