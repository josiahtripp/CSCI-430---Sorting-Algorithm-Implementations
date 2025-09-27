#include <bubblesorta.h>

void bubblesorta(std::vector<int> &ar){

    size_t n = ar.size();

    for(size_t i = 0; i < n - 1; i++){
        for(size_t j = n - 1; j > i; j--){
            if(ar[j] < ar[j-1]){
                int temp = ar[j];
                ar[j] = ar[j-1];
                ar[j-1] = temp;
            }
        }
    }
}