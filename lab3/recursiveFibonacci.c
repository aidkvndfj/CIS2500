#include "lab3.h"

int recursiveFibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }

    return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}