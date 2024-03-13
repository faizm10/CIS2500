#include <stdio.h>
#include "../include/givenA2.h"
#include <stdlib.h> 
/*
*
Student Name: Faiz Mustansar
Student ID: 1261489
Due Date: 10 March 2024
Course: CIS*2500
I have exclusive control over this submission via my password.
By including this header comment, I certify that:
1) I have read and understood the policy on academic integrity.
2) I have completed Moodle's module on academic integrity.
3) I have achieved at least 80% on the academic integrity quiz
I assert that this work is my own. I have appropriate acknowledged any and all material that I have used, be it directly quoted or
paraphrased. Furthermore, I certify that this assignment was written
by me in its entirety.
*/
void readContacts(char *fileName) {
    FILE *file = fopen(fileName, "rb"); // Open the file in binary read mode
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    struct contact c;
    while (fread(&c, sizeof(struct contact), 1, file) == 1) {
        printf("****************************\n");

        // Read and print Employee ID
        fseek(file, c.empIdPosn, SEEK_SET);
        int empId;
        fread(&empId, sizeof(int), 1, file);
        printf("Employee Id: %d\n", empId);

        // Read and print First Name if it doesnt have space only
        if (c.firstNamePosn > 0) {
            fseek(file, c.firstNamePosn, SEEK_SET);
            char firstName[100]; 
            fread(firstName, sizeof(char), 100, file);
            printf("First Name: %s\n", firstName);
        }

        // Read and print Last Name if it doesnt have space only
        if (c.lastNamePosn > 0) {
            fseek(file, c.lastNamePosn, SEEK_SET);
            char lastName[100]; 
            fread(lastName, sizeof(char), 100, file);
            printf("Last Name: %s\n", lastName);
        }

        // Read and print Email if it doesnt have space only
        if (c.emailPosn > 0) {
            fseek(file, c.emailPosn, SEEK_SET);
            char email[100];
            fread(email, sizeof(char), 100, file);
            printf("Email: %s\n", email);
        }

        printf("****************************\n\n");

        // Move to the next record
        fseek(file, c.next, SEEK_SET);
    }

    fclose(file); // Close the file
}
