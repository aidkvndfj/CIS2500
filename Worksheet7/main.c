#include "main.h"

int main(void) {
    int arr[5];
    int sumRec = 0;
    
    arr [0] = 1;
    arr [1] = 4;
    arr [2] = -3;
    arr [3] = 2;
    arr [4] = 6;


    // for (int i = 0; i < 5; i++){
    //     arr[i] = 1;
    // }

    sumRec = sumR(arr, 5);
    printf("Size: %d\n", sumRec);

    for (int i = 0; i < 5; i++) {
        printf("%d\n", arr[i]);
    }

    reverseMe(arr, 5);
    printf("\n\n");

    for (int i = 0; i < 5; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}

int sumR(int arr[], int size) {
    if(size <= 0) {
        return 0;
    } else {
        return sumR(arr, size - 1) + arr[size - 1];
    }
}

void reverseMe (int arr[], int size) {
    int temp;

    if (size > 1) {
        temp = arr[0];
        arr[0] = arr[size - 1];
        arr[size - 1] = temp;
        reverseMe(arr+1, size - 2);
    }
}