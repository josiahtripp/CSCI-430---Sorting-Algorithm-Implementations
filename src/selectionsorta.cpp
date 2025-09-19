#include <selectionsorta.h>

void selectionsorta(std::vector<int> &ar){

    int n = ar.size();
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if (ar[j] < ar[i]){
                int temp = ar[j];
                ar[j] = ar[i];
                ar[i] = temp;
            }
        }
    }
}