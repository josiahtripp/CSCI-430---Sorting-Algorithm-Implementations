#include <iostream>
#include <vector>
#include <cmath>
#include <string>

#include <selectionsorta.h>
#include <selectionsortb.h>
#include <mergesort.h>
#include <quicksort.h>
#include <insertionsort.h>
#include <bubblesorta.h>
#include <bubblesortb.h>
#include <bubblesortc.h>
#include <countingsort.h>
#include <radixsort.h>


// Define NULL
#ifndef NULL
    #define NULL (void) 0
#endif

// Maximum and minimum random range
#define MAX_INT 1000
#define MIN_INT -1000


// Size of array to be sorted
#define ARR_SIZE 100

// Total number of sorting algorithms to be tested
#define NUM_ALGS 10

// Returns a vector of random integers
// Number of elements = param[int size]
std::vector<int> randVector(std::size_t size)
{
    std::vector<int> rVec;
    rVec.reserve(size);

    for(long unsigned int i = 0; i < size; i++)
    {    
        rVec.push_back(rand() % (MAX_INT - MIN_INT + 1) + MIN_INT);
    }

    return rVec;
}

// Prints a vector as a bracketed list
void printVector(std::vector<int> &ar)
{
    // Number of elements per row of printed list
    const static unsigned int rowElements = 15;
    
    // Number of total rows
    unsigned int rows = (unsigned int) ceil((double) ar.size() / rowElements);

    // Print vector
    std::cout << "[ ";
    for(unsigned int i = 0; i < rows; i++){

        if(i != 0){
            std::cout << "  ";
        }

        unsigned int j = i * rowElements;
        while(j < ar.size() - 1 && j < (i + 1) * rowElements){

            std::cout << ar[j] << ", ";
            j++;
        }

        if(j == ar.size() - 1){
            std::cout << ar[j]  << " ]";
            j++;
        }
        std::cout << "\n";
    }
}

bool checkSort(std::vector<int> &ar)
{
    int lastElement = ar[0];

    for(int element : ar){

        if (element < lastElement){
            return false;
        }
        lastElement = element;
    }
    return true;
}

int main()
{
    // Set seed for random integer generation
    srand(time(NULL));

    // Sorting functions to test
    void(*algorithms[NUM_ALGS])(std::vector<int>&) = {
        selectionsorta,
        selectionsortb,
        mergesort,
        quicksort,
        insertionsort,
        bubblesorta,
        bubblesortb,
        bubblesortc,
        countingsort,
        radixsort
    };

    // Names of sorting functions
    std::string names[NUM_ALGS] = {
        "selection sort A",
        "selection sort B",
        "merge sort",
        "quick sort",
        "insertion sort",
        "bubble sort A",
        "bubble sort B",
        "bubble sort C",
        "counting sort",
        "radix sort"
    };

    for(int i = 0; i < NUM_ALGS; i++)
    {
        std::cout << "Generating random vector...(" << ARR_SIZE << " elements)\n";
        std::vector<int> ar = randVector(ARR_SIZE);

        std::cout << "Sorting vector with " << names[i] << "...\n";
        algorithms[i](ar);

        std::cout << "Printing sorted vector...\n";
        printVector(ar);

        if(checkSort(ar)){
            std::cout << "Valid Sort\n\n";
        }
        else{
            std::cout << "Invalid Sort\n\n";
        }
    }

    return 0;
}