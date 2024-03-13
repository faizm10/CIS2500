#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/givenA2.h"
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
void createContacts(char *fileName) {
    FILE *file = fopen(fileName, "ab+"); // ppen for appending and reading in binary mode
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    // get contact information from user
    int empId;
    do
    {
        printf("Enter Employee ID (1-9999): ");
        scanf("%d", &empId);
        // for new line character
        while (getchar() != '\n')
            ;

    } while (empId < 1 || empId > 9999);
    char *firstName = (char *)malloc(100 * sizeof(char));
    char *lastName = (char *)malloc(100 * sizeof(char));
    char *email = (char *)malloc(100 * sizeof(char));

    // printf and fgets statements for user input 
    printf("Enter First Name: ");
    fgets(firstName, 100, stdin);
    firstName[strlen(firstName) - 1] = '\0';
    printf("Enter Last Name: ");
    fgets(lastName, 100, stdin);
    lastName[strlen(lastName) - 1] = '\0';
    printf("Enter Email: ");
    fgets(email, 100, stdin);
    email[strlen(email) - 1] = '\0';
    printf("\n");

    // Seek to the end of the file
    fseek(file, 0, SEEK_END);

    struct contact newContact;
    long startPos = ftell(file);

    // Calculate positions for each field
    newContact.empIdPosn = startPos + sizeof(struct contact);
    newContact.firstNamePosn = newContact.empIdPosn + sizeof(empId);
    newContact.lastNamePosn = newContact.firstNamePosn + strlen(firstName) + 1; 
    newContact.emailPosn = newContact.lastNamePosn + strlen(lastName) + 1; 
    newContact.next = newContact.emailPosn + strlen(email) + 1; 

    fwrite(&newContact, sizeof(struct contact), 1, file);

    // Write the Employee ID, First Name, Last Name, and Email to the file
    fwrite(&empId, sizeof(empId), 1, file);
    fwrite(firstName, strlen(firstName) + 1, 1, file);
    fwrite(lastName, strlen(lastName) + 1, 1, file); 
    fwrite(email, strlen(email) + 1, 1, file); 

    fclose(file); // Close the file
}
