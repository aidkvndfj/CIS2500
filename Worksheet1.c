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

void oneMoreDone(gradStudent student) {
    student.numCoursesDone += 1;
}

int main(void) {
    gradStudent g1;
    strcpy(g1.name, "max");
    printf("%s", g1.name);
    g1.numCoursesDone = 3;
    g1.currentPercentage = 87;

    return 0;
}