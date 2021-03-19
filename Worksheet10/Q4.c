#include <stdio.h>

int dum (int (*f)(int), int start, int end);
int f(int i);

int main() {
    printf("Answer = %d \n", dum (f, 1, 4));
    return 0;
}

int dum (int (*f)(int), int start, int end) {
    int total;
    total = 0;
    for (int i = start; i < end; i++) {
        total += (*f)(i);
    }
    return total;
}

int f (int i ) {
    return i*i;
}