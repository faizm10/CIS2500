#include "../include/givenA2.h"
#include <stdio.h>
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
int searchContacts(char *fileName, int keyId) {
    FILE *file = fopen(fileName, "rb"); // Open the file in binary read mode
    if (file == NULL) {
        perror("Error opening file");
        return 0;
    }

    struct contact c;
    int found = 0; 
    while (fread(&c, sizeof(struct contact), 1, file) == 1) {
        // Read Employee ID and compare with keyId
        fseek(file, c.empIdPosn, SEEK_SET);
        int empId;
        fread(&empId, sizeof(int), 1, file);
        if (empId == keyId) {
            found = 1; //one match was found (there may be more duplicate id)
            printf("****************************\n");
            printf("Employee Id: %d\n", empId);

            //Read and print First Name if present
            if (c.firstNamePosn > 0) {
                fseek(file, c.firstNamePosn, SEEK_SET);
                char firstName[100]; 
                fread(firstName, sizeof(char), 100, file);
                printf("First Name: %s\n", firstName);
            }

            //Read and print Last Name if present
            if (c.lastNamePosn > 0) {
                fseek(file, c.lastNamePosn, SEEK_SET);
                char lastName[100]; // Assuming last name won't exceed 99 characters
                fread(lastName, sizeof(char), 100, file);
                printf("Last Name: %s\n", lastName);
            }

            //Read and print Email if present
            if (c.emailPosn > 0) {
                fseek(file, c.emailPosn, SEEK_SET);
                char email[100]; // Assuming email won't exceed 99 characters
                fread(email, sizeof(char), 100, file);
                printf("Email: %s\n", email);
            }

            printf("****************************\n");
        }

        // Move to the next record's position if not at the end of the file
        if (c.next > 0) {
            fseek(file, c.next, SEEK_SET);
        }
    }

    fclose(file); // Close the file

    if (found) {
        return 1; // Return 1 if match was found
    } else {
        printf("No match found.\n");
        return 0; // Return 0 if no match was found
    }
}

