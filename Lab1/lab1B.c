#include "lab1.h"


void printAnEmployee(Employees employee)
{
    printf("First Name: %s\n", employee.fname);
    printf("Last Name: %s\n", employee.lname);
    printf("ID: %d\n", employee.id);
    printf("Dependents:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Dependents %d: %s\n", i, employee.dependents[i]);
    }
}

int searchFirstName(char *fname, Employees arrEmployees[])
{
    for (int i = 0; i < NUM_EMP; i++)
    {
        if (strcmp(arrEmployees[i].fname, fname) == 0)
        {
            return arrEmployees[i].id;
        }
    }

    return -1;
}
