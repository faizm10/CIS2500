#include "lab1.h"


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    char *fileName = argv[1];

    // Load employees from the file
    Employees employees[NUM_EMP];
    int result = loadEmployees(employees, fileName);
    printf("Loaded: %d\n", result);
    printAnEmployee(employees[0]);

    char targetName[20];
    printf("Enter Name to be Searched: ");
    scanf("%s", targetName);
    int employeeID = searchFirstName(targetName, employees);

    if (employeeID != -1)
    {
        printf("Employee ID for %s: %d\n", targetName, employeeID);
    }
    else
    {
        printf("Employee with first name %s not found\n", targetName);
    }

    return 0;
}



