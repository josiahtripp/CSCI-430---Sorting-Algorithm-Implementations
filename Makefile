all:
	g++ -c -I include src/main.cpp src/ssorta.cpp src/ssortb.cpp src/msort.cpp src/qsort.cpp
	g++ -o sortingalgs main.o ssorta.o ssortb.o msort.o qqsort.o
	rm *.o