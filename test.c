#define MAX_LEN_NAME 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct justATag {
    char name[MAX_LEN_NAME];
    char* supervisor;
    int numCoursesDone;
    float currentPercentage;
} gradStudent;

int main(void) {
    gradStudent g1;
    strcpy("Max", g1.name);
    printf("%s", g1.name);

    return 0;
}