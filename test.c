#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    for (int i = 0; i < 1000; i++) {
        // printf("%d\n", (1 + rand() * (999 - 1) / RAND_MAX));
        printf("%d\n", (1 + rand() % (999-1)));
    }

    return 0;
}