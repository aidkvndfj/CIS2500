#include "lab3.h"

int main(int argc, char* argv[]) {
    /* test Cases
    int i;
    int fibAnwsers[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377};
    int fibAnwser;
    int sumAnwsers[] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169};
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
            printf("Iterative Sum Of of %d odds: %d \033[0;32m PASS \033[0m \n", i, sumAnwser);
        }
        else {
            printf("Iterative Sum Of of %d odds: %d \033[0;31m FAIL \033[0m \n", i, sumAnwser);
        }
    }

    for (i = 0; i < 14; i++) {
        sumAnwser = recursiveSumNOdd(i);
        if (sumAnwser == sumAnwsers[i]) {
            printf("Recursive Sum Of of %d odds: %d \033[0;32m PASS \033[0m \n", i, sumAnwser);
        }
        else {
            printf("Recursive Sum Of of %d odds: %d \033[0;31m FAIL \033[0m \n", i, sumAnwser);
        }
    }
    */

    if (argc != 2) {
        printf("ERROR | USAGE: ./lab3 <Integer>.\n");
        return -1;
    }

    clock_t begin, end;

    int n;
    double iterativeFibonacciTimeResults;
    double recursiveFibonacciTimeResults;
    double iterativeSumNOddTimeResults;
    double recursiveSumNOddTimeResults;

    n = (atoi(argv[1]));
    iterativeFibonacciTimeResults = 0.0;
    recursiveFibonacciTimeResults = 0.0;
    iterativeSumNOddTimeResults = 0.0;
    recursiveSumNOddTimeResults = 0.0;

    begin = clock();
    iterativeFibonacci(n);
    end = clock();
    iterativeFibonacciTimeResults += (double)(end - begin) / CLOCKS_PER_SEC;

    // explodes at n=45
    begin = clock();
    recursiveFibonacci(n);
    end = clock();
    recursiveFibonacciTimeResults += (double)(end - begin) / CLOCKS_PER_SEC;

    begin = clock();
    iterativeSumNOdd(n);
    end = clock();
    iterativeSumNOddTimeResults += (double)(end - begin) / CLOCKS_PER_SEC;

    begin = clock();
    recursiveSumNOdd(n);
    end = clock();
    recursiveSumNOddTimeResults += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Time to complete iterative Fibonacci of size %d: %05.2lf seconds.\n", n, iterativeFibonacciTimeResults);
    printf("Time to complete recursive Fibonacci of size %d: %05.2lf seconds.\n", n, recursiveFibonacciTimeResults);
    printf("Time to complete iterative Sum_N_Odd of size %d: %05.2lf seconds.\n", n, iterativeSumNOddTimeResults);
    printf("Time to complete recursive Sum_N_Odd of size %d: %05.2lf seconds.\n", n, recursiveSumNOddTimeResults);
    return 0;
}