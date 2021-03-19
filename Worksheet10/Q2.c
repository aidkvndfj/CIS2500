#include <stdio.h>

int sumOfSquare(int num1, int num2);
int sum(int num1, int num2);

int mysteryWS10(int num1, int num2, int (*fun)(int, int));

int main() {
    printf("%d \n", mysteryWS10(2, 10, sum));
    printf("%d \n", mysteryWS10(2, 10, sumOfSquare));
    printf("%d \n", mysteryWS10(2, sum(3, 4), sumOfSquare));

    return 0;
}

int sum (int num1, int num2) {
    return num1  + num2;
}

int sumOfSquare(int num1, int num2) {
    return (num1 * num1 + num2 * num2);
}

int mysteryWS10(int num1, int num2, int (*fun)(int, int)) {
    return (*fun)(num1, num2);
}