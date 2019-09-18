# CC and CFLAGS are varilables 
CC=g++
CFLAGS =  -c 
# -c option ask g++ to compile the source files, but do not link.
# -g option is for debugging version
# -O2 option is for optimized version
DBGFLAGS = -g -D_DEBUG_ON_
OPTFLAGS = -O2


# DEBUG Version
demo_dbg	: mergeSort_dbg main_dbg
			$(CC) $(DBGFLAGS) mergeSort.o main.o -ltm_usage -Llib -o bin/demo_dbg
main_dbg 	   	:  lib/tm_usage.h  src/global.h src/main.cpp 
			$(CC) $(CFLAGS)  src/main.cpp   -Ilib
mergeSort_dbg	: src/mergeSort.cpp src/mergeSort.h
			$(CC) $(CFLAGS) $(DBGFLAGS) src/mergeSort.h src/mergeSort.cpp 
			
# optimized version
demo_opt	: mergeSort_opt main_opt
			$(CC) $(OPTFLAGS) mergeSort.o main.o -ltm_usage -Llib -o bin/demo_opt
main_opt 	   	:  lib/tm_usage.h  src/global.h src/main.cpp 
			$(CC) $(CFLAGS)  src/main.cpp   -Ilib
mergeSort_opt	: src/mergeSort.cpp src/mergeSort.h
			$(CC) $(CFLAGS) $(OPTFLAGS) src/mergeSort.h src/mergeSort.cpp 

# clean all the .o and executable files
clean:
		rm -rf *.o bin/demo_*
