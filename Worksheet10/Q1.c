#include <stdio.h>
#include <stdlib.h>

void * addI (void * a, void * b);

int main() {

    int * ans;
    int c = 4, d = 10;

    void * (*f) (void*, void*) = addI;

    ans = (int*) f(&c, &d);

    printf("%d \n", *ans);

    return 0;
}

void * addI (void * a, void * b) {

    int * temp = malloc(sizeof(int));

    // need to case as int
    *temp = *(int*)a + *(int*)b;

    return temp;
}