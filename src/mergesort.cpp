#include <mergesort.h>

void mergesorthelper(std::vector<int> &ar, int p, int r){

    if(p >= r){
        return;
    }
    int q = (p + r) / 2;
    mergesorthelper(ar, p, q);
    mergesorthelper(ar, q + 1, r);

    int NL = q - p + 1;
    int NR = r - q;

    std::vector<int> L, R;
    L.reserve(NL);
    R.reserve(NR);

    for(int i = 0; i < NL; i++){
        L[i] = ar[p+i];
    }
    for(int j = 0; j < NR; j++){
        R[j] = ar[q+j+1];
    }

    int i = 0;
    int j = 0;
    int k = p;

    while(i < NL && j < NR){
        if(L[i] <=R[j]){
            ar[k] = L[i];
            i++;
        }
        else{
            ar[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < NL){
        ar[k] = L[i];
        i++;
        k++;
    }

    while(j < NR){
        ar[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(std::vector<int> &ar){

    mergesorthelper(ar, 0, ar.size() - 1);
}