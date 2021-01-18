// defines
#define MAX_LEN_NAME 20

// invludes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structs
typedef struct justATag {
    char name[MAX_LEN_NAME];
    char* supervisor;
    int numCoursesDone;
    float currentPercentage;
} gradStudent;

// prototypes
void oneMoreDone(gradStudent*);
void swapSupervisors(gradStudent*, gradStudent*);

// functions
void oneMoreDone(gradStudent* student) {
    float grade;
    float newPercentage;

    printf("\nPlease input your grade for the course (max of 100%%): ");
    scanf("%f", &grade);
    while (grade > 100 || grade < 0) {
        printf("Error, invalid grade, please try again: ");
        scanf("%f", &grade);
    }

    // newPercentage = student->currentPercentage * ((float)student->numCoursesDone / (student->numCoursesDone + 1));
    newPercentage = ((((float)(student->numCoursesDone - 1) / student->numCoursesDone) * student->currentPercentage) + ((1 - ((float)(student->numCoursesDone - 1) / student->numCoursesDone)) * grade));
    student->currentPercentage = newPercentage;
    student->numCoursesDone += 1;
}

void swapSupervisors(gradStudent* student1, gradStudent* student2) {
    gradStudent* tempStudent;

    tempStudent = student1;
    *student1 = *student2;
    *student2 = *tempStudent;
}

// main
int main(void) {
    gradStudent g1;
    gradStudent g2;
    strcpy(g1.name, "Harry Dang");

    g1.supervisor = malloc(sizeof(char) * MAX_LEN_NAME);
    strcpy(g1.supervisor, "Ria Jonas");
    g1.numCoursesDone = 3;
    g1.currentPercentage = 87.0;

    printf("%f\n", g1.currentPercentage);
    oneMoreDone(&g1);
    printf("%f\n", g1.currentPercentage);

    g2.supervisor = malloc(sizeof(char) * MAX_LEN_NAME);
    strcpy(g2.supervisor, "Dough Jonas");
    printf("%s\n%s\n", g1.supervisor, g2.supervisor);
    swapSupervisors(&g1, &g2);
    printf("%s\n%s\n", g1.supervisor, g2.supervisor);

    return 0;
}