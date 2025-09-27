#include <radixsort.h>

void radixsort(std::vector<int> &ar){

    // Number of bits in int
    const int d = 32;

    int n = ar.size();
    std::vector<int> C(2, 0);
    std::vector<int> B(ar);

    std::vector<int>* from = &ar;
    std::vector<int>* to = &B;

    // For every digit in int
    for(int i = 0; i < d; i++){

        unsigned int mask = 1U << i;

        C[0] = 0;
        C[1] = 0;

        if(i < d - 1){
            for(int j = 0; j < n; j++){
                C[((*from)[j] & mask) >> i]++;
            }
        }
        else{
            for(int j = 0; j < n; j++){
                C[(((*from)[j] & mask) >> i) ^ 1U]++;
            }
        }

        C[1] += C[0];

        if(i < d - 1){
            for(int j = n - 1; j > -1; j--){
                (*to)[C[((*from)[j] & mask )>> i] - 1] = (*from)[j];
                C[((*from)[j] & mask) >> i]--;
            }
        }
        else{
            for(int j = n - 1; j > -1; j--){
                (*to)[C[(((*from)[j] & mask) >> i) ^ 1U] - 1] = (*from)[j];
                C[(((*from)[j] & mask) >> i) ^ 1U]--;
            }
        }

        auto temp = from;
        from = to;
        to = temp;
    }
}