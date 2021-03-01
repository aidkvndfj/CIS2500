#include "lab3.h"

int iterativeFibonacci(int n) {
    if (n < 0) {
        return -1;
    } else if (n == 0) {
        return 0;
    } else if (n < 3) {
        return 1;
    }

    int i;
    int nextTerm1;
    int nextTerm2;
    int currTerm;

    nextTerm2 = 1;
    currTerm = 0;

    for (i = 1; i <= n; i++) {
        nextTerm1 = nextTerm2 + currTerm;
        currTerm = nextTerm2;
        nextTerm2 = nextTerm1;
    }

    return currTerm;
}