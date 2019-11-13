CFLAGS = -O3 -Wall -std=c++11

mps: main.o maxPlanarSubset.o
	g++ -o $@ main.o maxPlanarSubset.o $(CFLAGS)

main.o: src/main.cpp src/maxPlanarSubset.h
	g++ -c src/main.cpp $(CFLAGS)

maxPlanarSubset.o: src/maxPlanarSubset.cpp src/maxPlanarSubset.h
	g++ -c src/maxPlanarSubset.cpp $(CFLAGS)

clean:
	rm -f mps *.o

