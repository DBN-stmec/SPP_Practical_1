CC=gcc
CXX=g++
CFLAGS=-O3 -fopenmp -std=c99
CXXFLAGS=-O3 -fopenmp
EXECS=qsort

all: $(EXECS)

qsort : quicksort.cpp
	$(CXX) -o $@ $<  $(CXXFLAGS)

clean:
	rm -f $(EXECS) *.o
