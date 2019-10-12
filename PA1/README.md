# Promgram assignment #1: Sorting
Author: Shannon Lee (李尚倫)  
Date: 2019/10/06 Sunday  

## SYNOPSIS
This program supports four different sorting methods: **insertion sort**, **merge sort**, **quick sort** and **heap sort**. All of the source code files have been already given except sort_tool.cpp. I only complete the different sorting functions of class SortTool in sort_tool.cpp
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
```sh
make #or make all
#g++ -c -O2 src/sort_tool.cpp -o sort_tool_opt.o
#g++ -c src/main.cpp -Ilib -o main_opt.o
#g++ -c lib/tm_usage.cpp
#ar rcv lib/libtm_usage.a tm_usage.o
#a - tm_usage.o
#g++ -O2 sort_tool_opt.o main_opt.o -ltm_usage -Llib -o bin/NTU_sort
#building project
```
```sh
make dbg
#g++ -c -g -D_DEBUG_ON_ src/sort_tool.cpp -o sort_tool_dbg.o
#g++ -c src/main.cpp -Ilib -o main_dbg.o
#g++ -c lib/tm_usage.cpp
#ar rcv lib/libtm_usage.a tm_usage.o
#a - tm_usage.o
#g++ -g -D_DEBUG_ON_ sort_tool_dbg.o main_dbg.o -ltm_usage -Llib -o bin/NTU_sort_dbg
#building debugger
```

## HOW TO RUN & VERIFY:
Run the sorter
```
./bin/NTU_sort -[IS|MS|QS|HS] <input_file_name> <output_file_name>
```
Inputs and outputs
```
*.[case1|case2|case3].in, where 
case1 represents test case in random order (average case)
case2 is test case in increasing order (best case)
case3 is test case in reverse order (worst case)
```

## EXPERIMENT
Check the answers correctness, and get memory usage and cpu time.
```
bash src/insertionSort.sh > outputs/insertionSort.log
bash src/mergeSort.sh > outputs/mergeSort.log
bash src/quickSort.sh > outputs/quickSort.log
bash src/heapSort.sh > outputs/heapSort.log
```
Comparison table  
<img src="TBD.jpg" width=400/>  
Draw figures to show the growth of running time as a function of input size  
<img src="TBD.jpg" width=400/>  

## TESTING
Verify the output by given exeacutable file
```
./utility/PA1_Result_Checker <input_file> <result_file_name>
```
SelfCheck of homework upload
```
mkdir r07921001_pa1
cp -r {src,lib,bin,doc,makefile,README.md} ./r07921001_hw2
tar zcvf r07921001_pa1.tgz r07921001_pa1
./utility/checkSubmitPA1.sh r07921001_hw2.tgz
```

## OTHER NOTICE:
If your code run well for small test case but get "Segmentation fault" for the large test case, you can use the the following commend to increase the stack size to 256MB:
```sh
ulimit -a                # To list all constraints 
ulimit -s 262144         # To change stack size to 256mb
```
