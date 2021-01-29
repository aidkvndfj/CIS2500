#define MAX_LEN_NAME 20
#define MAX_GRAD_STUDENTS 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct justTag {
    char name[MAX_LEN_NAME];
    char supervisor[MAX_LEN_NAME];
    int numCoursesDone;
    float currentPercentage;
} gradStudent;

int read1Grads(FILE *file, gradStudent gsArray[MAX_GRAD_STUDENTS]);
int read2Grads(FILE *file, gradStudent gsArray[MAX_GRAD_STUDENTS]);
void printGrad(gradStudent);

int main() {
    // gradStudent g1, g2;
    int numRead;
    gradStudent gsArray[MAX_GRAD_STUDENTS];
    FILE *fptr = fopen("file1.txt", "r");

    numRead = read1Grads(fptr, gsArray);

    for (int i = 0; i < numRead; i++) {
        printGrad(gsArray[i]);
    }
    return 0;
}

int read1Grads(FILE *file, gradStudent gsArray[MAX_GRAD_STUDENTS]) {
    int studentCounter;

    studentCounter = 0;
    while (!feof(file)) {
        fgets(gsArray[studentCounter].name, MAX_LEN_NAME, file);
        strtok(gsArray[studentCounter].name, "\n");
        fgets(gsArray[studentCounter].supervisor, MAX_LEN_NAME, file);
        strtok(gsArray[studentCounter].supervisor, "\n");
        fscanf(file, " %d ", &gsArray[studentCounter].numCoursesDone);
        fscanf(file, "%f ", &gsArray[studentCounter].currentPercentage);
        studentCounter++;
    }

    return studentCounter;
}

int read2Grads(FILE *file, gradStudent gsArray[MAX_GRAD_STUDENTS]) {
    int studentCounter;

    studentCounter = 0;
    while (!feof(file)) {
        fscanf(file, "%s %s %d %f", gsArray[studentCounter].name, gsArray[studentCounter].supervisor, &gsArray[studentCounter].numCoursesDone, &gsArray[studentCounter].currentPercentage);
        studentCounter++;
    }

    return studentCounter;
}

void printGrad(gradStudent g) {
    printf("Name: %s\n", g.name);
    printf("Supervisor: %s\n", g.supervisor);
    printf("Number of Courses Done so far: %d\n", g.numCoursesDone);
    printf("Current percentage: %.2f\n", g.currentPercentage);
}