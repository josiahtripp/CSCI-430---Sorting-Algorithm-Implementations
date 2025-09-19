#include <quicksort.h>

void quicksorthelper(std::vector<int> &ar, int p, int r){

    if(p < r){
        int x = ar[r];
        int i = p - 1;
        for(int j = p; j < r; j++){
            if(ar[j] <= x){
                i++;
                int temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
        int temp = ar[i+1];
        ar[i+1] = ar[r];
        ar[r] = temp;
        int q = i + 1;

        quicksorthelper(ar, p, q-1);
        quicksorthelper(ar, q+1, r);
    }
}

void quicksort(std::vector<int> &ar){

    quicksorthelper(ar, 0, ar.size() - 1);
}