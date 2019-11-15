CFLAGS = -O3 -Wall -std=c++11
DBGFLAGS = -g -Wall -std=c++11

# Optimized version
all: mps
	@echo -n "building project\n"

mps: main.o maxPlanarSubset.o
	g++ -o $@ main.o maxPlanarSubset.o $(CFLAGS)

main.o: src/main.cpp src/maxPlanarSubset.h
	g++ -c src/main.cpp $(CFLAGS)

maxPlanarSubset.o: src/maxPlanarSubset.cpp src/maxPlanarSubset.h
	g++ -c src/maxPlanarSubset.cpp $(CFLAGS)

# DEBUG Version
debug: mps_debug
	@echo -n "building debugging version\n"

mps_debug: main_dbg.o maxPlanarSubset_dbg.o
	g++ -o $@ main.o maxPlanarSubset.o $(DBGFLAGS)

main_dbg.o: src/main.cpp src/maxPlanarSubset.h
	g++ -c src/main.cpp $(DBGFLAGS)

maxPlanarSubset_dbg.o: src/maxPlanarSubset.cpp src/maxPlanarSubset.h
	g++ -c src/maxPlanarSubset.cpp $(DBGFLAGS)

clean:
	rm -f mps mps_debug *.o

