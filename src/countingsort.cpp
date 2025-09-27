#include <countingsort.h>
#include <iostream>
#include <algorithm>

void countingsort(std::vector<int> &ar){

    int k_min = ar[0];
    int k_max = ar[0];
    int n = (int) ar.size();
    for(int i = 1; i < n; i++){

        if(ar[i] < k_min){
            k_min = ar[i];
        }
        if(ar[i] > k_max){
            k_max = ar[i];
        }
    }

    std::vector<int> C(k_max - k_min + 1, 0);
    std::vector<int> B(ar);

    for(int i = 0; i < n; i++){
        C[ar[i] - k_min]++;
    }

    for(size_t i = 1; i < C.size(); i++){
        C[i] += C[i-1];
    }

    for(int i = n - 1; i > -1; i--){
        ar[C[B[i] - k_min] - 1] = B[i];
        C[B[i] - k_min]--;
    }
}