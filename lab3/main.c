#include "lab3.h"

int main(void) {
    int i;
    int fibAnwsers[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377};
    int fibAnwser;

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

    return 0;
}