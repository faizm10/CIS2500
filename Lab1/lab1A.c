#include "lab1.h"
void saveEmployees(Employees arrEmployees[NUM_EMP], int c, char *fileName)
{
    if (c > NUM_EMP)
    {
        printf("Invalid number of records to save.\n");
        return;
    }
    FILE *fp = fopen(fileName, "w");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }
    for (int i = 0; i < c; i++)
    {
        fprintf(fp, "%s\n%s\n%d\n", arrEmployees[i].fname, arrEmployees[i].lname,
                arrEmployees[i].id);
        for (int j = 0; j < 3; j++)
        {
            fprintf(fp, "%s\n", arrEmployees[i].dependents[j]);
        }
    }
    fclose(fp);
}
int loadEmployees(Employees arrEmployees[NUM_EMP], char *fileName) {
    int result = 0;
    FILE *fp = fopen(fileName, "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        return 0;
    } else {
        while (fscanf(fp, "%s%s%d", arrEmployees[result].fname,
                      arrEmployees[result].lname, &arrEmployees[result].id) == 3) {
            // Read dependents
            for (int j = 0; j < 3; j++) {
                fscanf(fp, "%s", arrEmployees[result].dependents[j]);
            }
            result++;
            // Check if there is space for more employees
            if (result >= NUM_EMP) {
                break;
            }
        }
    }

    fclose(fp);
    return result;
}
