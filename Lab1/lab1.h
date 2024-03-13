#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 25
#define NUM_EMP 10

struct employee
{
    char fname[20];
    char lname[20];
    int id;
    char dependents[3][20];
};

typedef struct employee Employees;

void saveEmployees(Employees arrEmployees[NUM_EMP], int c, char *fileName);
int loadEmployees(Employees arrEmployees[NUM_EMP], char *fileName);
void printAnEmployee(Employees employee);
int searchFirstName(char *fname, Employees arrEmployees[]);