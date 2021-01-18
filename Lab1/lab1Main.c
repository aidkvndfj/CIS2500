#include "lab1.h"

int main(int argc, char* argv[]) {
    // main vars
    char fileName[SIZE];
    int numLoaded;

    Employees employeeList[NUM_EMP];
    // Employees employee1;
    // Employees employee2;

    // check to make sure they gave a filename
    if (argc != 2) {
        printf("ERROR: TOO MANY OR FEW ARGUMENTS GIVEN.\n");
        return 1;
    }
    // copy the filename to the variable
    strcpy(fileName, argv[1]);

    // data for testing saveEmployees without using loadEmployees

    // strcpy(employee1.fname, "Eric");
    // strcpy(employee1.lname, "Morse");
    // employee1.id = 7597;
    // strcpy(employee1.dependents[0], "Cam");
    // strcpy(employee1.dependents[1], "Nick");

    // strcpy(employee2.fname, "Cam");
    // strcpy(employee2.lname, "Wonderwall");
    // employee2.id = 2635;
    // strcpy(employee2.dependents[0], "Eric");
    // strcpy(employee2.dependents[1], "Nick");

    // employeeList[0] = employee1;
    // employeeList[1] = employee2;

    // load employees info
    numLoaded = loadEmployees(employeeList, fileName);
    printf("Num Loaded: %d\n", numLoaded);

    // print the employees info
    printEmployees(employeeList, numLoaded);

    //swap employees
    swapEmployees(&employeeList[0], &employeeList[1]);

    // print the employees info again
    printEmployees(employeeList, numLoaded);

    // save the employees info to a txt
    // saveEmployees(employeeList, 2, fileName);

    return 0;
}