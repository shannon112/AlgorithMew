# CC and CFLAGS are varilables
CC = g++
CFLAGS = -c
AR = ar
ARFLAGS = rcv
# -c option ask g++ to compile the source files, but do not link.
# -g option is for debugging version
# -O2 option is for optimized version
DBGFLAGS = -g -D_DEBUG_ON_
OPTFLAGS = -O2


# Optimized version
all	: bin/NTU_sort
	@echo -n "building project\n"

bin/NTU_sort	: sort_tool_opt.o main_opt.o lib
			$(CC) $(OPTFLAGS) sort_tool_opt.o main_opt.o -ltm_usage -Llib -o bin/NTU_sort
main_opt.o 	   	: src/main.cpp lib/tm_usage.h
			$(CC) $(CFLAGS) $< -Ilib -o $@
sort_tool_opt.o	: src/sort_tool.cpp src/sort_tool.h
			$(CC) $(CFLAGS) $(OPTFLAGS) $< -o $@


# DEBUG Version
dbg : bin/NTU_sort_dbg
	@echo -n "building debugger\n"

bin/NTU_sort_dbg	: sort_tool_dbg.o main_dbg.o lib
			$(CC) $(DBGFLAGS) sort_tool_dbg.o main_dbg.o -ltm_usage -Llib -o bin/NTU_sort_dbg
main_dbg.o 	   	: src/main.cpp lib/tm_usage.h
			$(CC) $(CFLAGS) $< -Ilib -o $@
sort_tool_dbg.o	: src/sort_tool.cpp src/sort_tool.h
			$(CC) $(CFLAGS) $(DBGFLAGS) $< -o $@


# Library: objective files can be archived into a static library file lib*.a
lib: lib/libtm_usage.a
	@echo -n "building library\n"

lib/libtm_usage.a: tm_usage.o
	$(AR) $(ARFLAGS) $@ $<
tm_usage.o: lib/tm_usage.cpp lib/tm_usage.h
	$(CC) $(CFLAGS) $<


# Clean all the .o and executable files
clean:
		rm -rf *.o lib/*.a lib/*.o bin/*
