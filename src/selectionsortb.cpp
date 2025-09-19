#include <selectionsortb.h>

void selectionsortb(std::vector<int> &ar){

    int n = ar.size();
    for(int i = 0; i < n; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if (ar[j] < ar[min]){
                min = j;
            }
        }
        int temp = ar[i];
        ar[i] = ar[min];
        ar[min] = temp;
    }
}