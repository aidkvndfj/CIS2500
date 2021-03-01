#include "lab3.h"

int iterativeSumNOdd(int n) {
    int i;
    int total;
    
    total = 0;
    for (i = 1; i < n * 2; i += 2) {
        total += i;
    }

    return total;
}