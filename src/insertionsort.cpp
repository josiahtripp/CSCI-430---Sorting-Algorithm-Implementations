#include <insertionsort.h>
#include <iostream>

void insertionsort(std::vector<int> &ar){

    int n = (int) ar.size();

    for(int i = 1; i < n; i++){
        int key = ar[i];
        int j = i - 1;
        while(j >= 0 && ar[j] > key){
            ar[j+1] = ar[j];
            j--;
        }
        ar[j+1] = key;
    }
}