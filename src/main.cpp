#include <iostream>
#include <vector>
#include <ssorta.h>
#include <ssortb.h>
#include <msort.h>
#include <qsort.h>

#ifndef NULL
    #define NULL (void) 0
#endif

#define RAND_MAX __INT32_MAX__

#define ARR_SIZE 100

// Returns a vector of random integers
// Number of elements = param[int size]
std::vector<int> randVector(std::size_t size)
{
    std::vector<int> rVec;
    rVec.reserve(size);

    for(int i = 0; i < size; i++)
    {    
        rVec.push_back(rand());
    }

    return rVec;
}

int main(){

    // Set seed for random integer generation
    srand(time(NULL));

    std::vector<int> ar = randVector(ARR_SIZE)

}