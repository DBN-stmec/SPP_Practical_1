CC=gcc
CXX=g++
CFLAGS=-O3 -fopenmp -std=c99
CXXFLAGS=-O3 -fopenmp
EXECS=daxpy 

all: $(EXECS)

matmul_serial-sol: daxpy.cpp
	$(CXX) -o $@ $<  $(CXXFLAGS)

clean:
	rm -f $(EXECS) *.o
