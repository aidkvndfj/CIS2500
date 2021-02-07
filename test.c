#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int* ptr = NULL;
    int i;
    char ans = 'y';

    i = 0;
    while (ans == 'y') {
        if (ptr == NULL) {
            ptr = malloc(sizeof(int));
            ptr[i] = i * 2;
        }
        else {
            ptr = realloc(ptr, sizeof(int) * (i + 1));
            ptr[i] = i * 2;
        }

        i++;

        printf("Do you want to continue?");
        scanf("%c", &ans);
        getchar();
    }

    return 0;
}