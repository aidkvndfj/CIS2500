#include "lab1.h"

void printEmployees(Employees employeeList[NUM_EMP], int num) {
    int i;

    for (i = 0; i < num; i++) {
        printf("%s %s %d\nDependents: %s %s %s\n\n", employeeList[i].fname, employeeList[i].lname, employeeList[i].id, employeeList[i].dependents[0], employeeList[i].dependents[1], employeeList[i].dependents[2]);
    }
}

void saveEmployees(Employees employeeList[NUM_EMP], int num, char fileName[SIZE]) {
    int i;

    FILE* outFile = NULL;
    outFile = fopen(fileName, "w");

    for (i = 0; i < num; i++) {
        fprintf(outFile, "%s %s %d\nDependents: %s %s %s\n\n", employeeList[i].fname, employeeList[i].lname, employeeList[i].id, employeeList[i].dependents[0], employeeList[i].dependents[1], employeeList[i].dependents[2]);
    }

    fclose(outFile);
}