CFLAGS = -O3 -Wall -std=c++11
DBGFLAGS = -g -Wall -std=c++11

# Optimized version
all: cb
	@echo -n "building project\n"

cb: main.o cycleBreaking.o
	g++ -o $@ main.o cycleBreaking.o $(CFLAGS)

main.o: src/main.cpp src/cycleBreaking.h
	g++ -c src/main.cpp $(CFLAGS)

cycleBreaking.o: src/cycleBreaking.cpp src/cycleBreaking.h
	g++ -c src/cycleBreaking.cpp $(CFLAGS)

# DEBUG Version
debug: cb_debug
	@echo -n "building debugging version\n"

mps_debug: main_dbg.o cycleBreaking_dbg.o
	g++ -o $@ main.o cycleBreaking.o $(DBGFLAGS)

main_dbg.o: src/main.cpp src/cycleBreaking.h
	g++ -c src/main.cpp $(DBGFLAGS)

cycleBreaking_dbg.o: src/cycleBreaking.cpp src/cycleBreaking.h
	g++ -c src/cycleBreaking.cpp $(DBGFLAGS)

clean:
	rm -f cb cb_debug *.o

