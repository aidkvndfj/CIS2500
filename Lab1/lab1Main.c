#include "lab1.h"

int main(int argc, char* argv[]) {
    char fileName[SIZE];

    Employees employeeList[2];
    Employees employee1;
    Employees employee2;

    if (argc != 2) {
        printf("ERROR: TOO MANY OR FEW ARGUMENTS GIVEN.\n");
        return 1;
    }
    strcpy(fileName, argv[1]);

    strcpy(employee1.fname, "Eric");
    strcpy(employee1.lname, "Morse");
    employee1.id = 7597;
    strcpy(employee1.dependents[0], "Cam");
    strcpy(employee1.dependents[1], "Nick");

    strcpy(employee2.fname, "Cam");
    strcpy(employee2.lname, "Wonderwall");
    employee2.id = 2635;
    strcpy(employee2.dependents[0], "Eric");
    strcpy(employee2.dependents[1], "Nick");

    employeeList[0] = employee1;
    employeeList[1] = employee2;

    saveEmployees(employeeList, 2, fileName);

    return 0;
}