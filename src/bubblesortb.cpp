#include <bubblesortb.h>

void bubblesortb(std::vector<int> &ar){

    size_t n = ar.size();
    bool swapped;

    do{
        swapped = false;
        for(size_t  i = 0; i < n - 1; i++){
            if(ar[i] > ar[i+1]){
                int temp = ar[i];
                ar[i] = ar[i+1];
                ar[i+1] = temp;
                swapped = true;
            }
        }
    } while(swapped);
}