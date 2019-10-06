# Promgram assignment #1: Sorting
Author: Shannon Lee (李尚倫)  
Date: 2019/10/06 Sunday  

## SYNOPSIS
This program supports four different sorting methods: insertion sort, merge sort, quick sort and heap sort.
```
mysort -[IS|MS|QS|HS] <input_file_name> <output_file_name>
```

## DIRECTORY
```
bin/	  executable binary
doc/	  reports
inputs/   input data (unsorted)
outputs/  output result (sorted)
lib/	  library
src/ 	  source C++ codes
utility/  checker
```

## HOW TO COMPILE:
Then compile the demo, simply follow the following steps
```
make
```

## HOW TO RUN & VERIFY:
Run the sorter
```
./bin/NTU_sort -[IS|MS|QS|HS] <input_file_name> <output_file_name>
```
Verify the output by given exeacutable file
```
./utility/PA1_Result_Checker <input_file> <result_file_name>
```

## OTHER NOTICE:
If your code run well for small test case but get "Segmentation fault" for the large test case, you can use the the following commend to increase the stack size to 256MB:
```sh
ulimit -a                # To list all constraints 
ulimit -s 262144         # To change stack size to 256mb
```
