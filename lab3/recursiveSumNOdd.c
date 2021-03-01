#include "lab3.h"

int recursiveSumNOdd(int n) {
    if (n > 1) {
        return (n * 2 - 1) + recursiveSumNOdd(n - 1);
    } else {
        return 1;
    }
}