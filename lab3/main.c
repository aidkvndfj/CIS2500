#include "lab3.h"

int main(void) {
    int i;
    int fibAnwsers[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377};
    int fibAnwser;
    int sumAnwsers[] = {0, 1, 4, 8, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169};
    int sumAnwser;

    for (i = 0; i < 15; i++) {
        fibAnwser = iterativeFibonacci(i);
        if (fibAnwser == fibAnwsers[i]) {
            printf("Iterative Fibbonacci of %d: %d \033[0;32m PASS \033[0m \n", i, fibAnwser);
        }
        else {
            printf("Iterative Fibbonacci of %d: %d \033[0;31m FAIL \033[0m \n", i, fibAnwser);
        }
    }

    for (i = 0; i < 15; i++) {
        fibAnwser = recursiveFibonacci(i);
        if (fibAnwser == fibAnwsers[i]) {
            printf("Recursive Fibbonacci of %d: %d \033[0;32m PASS \033[0m \n", i, fibAnwser);
        }
        else {
            printf("Recursive Fibbonacci of %d: %d \033[0;31m FAIL \033[0m \n", i, fibAnwser);
        }
    }

    for (i = 0; i < 14; i++) {
        sumAnwser = iterativeSumNOdd(i);
        if (sumAnwser == sumAnwsers[i]) {
            printf("Iterative Sum Of of %d: %d \033[0;32m PASS \033[0m \n", i, sumAnwser);
        }
        else {
            printf("Iterative Sum Of of %d: %d \033[0;31m FAIL \033[0m \n", i, sumAnwser);
        }
    }

    for (i = 0; i < 14; i++) {
        sumAnwser = recursiveSumNOdd(i);
        if (sumAnwser == sumAnwsers[i]) {
            printf("Recursive Sum Of of %d: %d \033[0;32m PASS \033[0m \n", i, sumAnwser);
        }
        else {
            printf("Recursive Sum Of of %d: %d \033[0;31m FAIL \033[0m \n", i, sumAnwser);
        }
    }

    return 0;
}