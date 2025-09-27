#include <bubblesortc.h>

void bubblesortc(std::vector<int> &ar){

    size_t n = ar.size();
    bool swapped;

    do{
        swapped = false;
        for(size_t i = n - 1; i > 0; i--){
            if(ar[i-1] > ar[i]){
                int temp = ar[i-1];
                ar[i-1] = ar[i];
                ar[i] = temp;
                swapped = true;
            }
        }
    } while(swapped);
}