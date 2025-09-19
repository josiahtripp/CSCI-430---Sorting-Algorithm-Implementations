all:
	g++ -c -I include src/main.cpp src/selectionsorta.cpp src/selectionsortb.cpp src/mergesort.cpp src/quicksort.cpp
	g++ -o sortingalgs main.o selectionsorta.o selectionsortb.o mergesort.o quicksort.o
	rm *.o