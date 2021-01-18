#include "lab1.h"

void printEmployees(Employees employeeList[NUM_EMP], int num) {
    int i;

    // loop through the employees and print their f name, l name, id, and dependents
    for (i = 0; i < num; i++) {
        printf("%s %s %d\nDependents: %s %s %s\n\n", employeeList[i].fname, employeeList[i].lname, employeeList[i].id, employeeList[i].dependents[0], employeeList[i].dependents[1], employeeList[i].dependents[2]);
    }
}

void saveEmployees(Employees employeeList[NUM_EMP], int num, char fileName[SIZE]) {
    int i;

    // open the file
    FILE* outFile = NULL;
    outFile = fopen(fileName, "w");

    // loop through the employees and save their f name, l name, id, and dependents to a txt file.
    for (i = 0; i < num; i++) {
        fprintf(outFile, "%s %s %d\nDependents: %s %s %s\n\n", employeeList[i].fname, employeeList[i].lname, employeeList[i].id, employeeList[i].dependents[0], employeeList[i].dependents[1], employeeList[i].dependents[2]);
    }

    // close the file
    fclose(outFile);
}

int loadEmployees(Employees employeeList[NUM_EMP], char fileName[SIZE]) {
    int numEmployees;

    // open files and make sure it can read file
    FILE* inFile = NULL;
    inFile = fopen(fileName, "r");

    if (inFile == NULL) {
        printf("ERROR, COULD NOT OPEN FILE, FILE DOES NOT EXSIST, EXITING WITH -1\n\n");
        return -1;
    }

    numEmployees = 0;
    while (!feof(inFile)) {
        // get employee info
        fscanf(inFile, "%s %s %d", employeeList[numEmployees].fname, employeeList[numEmployees].lname, &employeeList[numEmployees].id);
        // get dependents
        fscanf(inFile, "%s %s %s", employeeList[numEmployees].dependents[0], employeeList[numEmployees].dependents[1], employeeList[numEmployees].dependents[2]);
        numEmployees++;
    }

    // return the number of employees read
    return numEmployees;
}

void swapEmployees(Employees* employee1, Employees* employee2) {
    // create a temp employee to store emplyee1 data while we overwrite it with employee2
    Employees tempEmployee;
    tempEmployee = *employee1;
    *employee1 = *employee2;
    *employee2 = tempEmployee;
}