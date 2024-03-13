/*
Student Name: Aisha Khan
Student ID: 1216274
Due Date: March 7, 2024
Course: CIS*2500
I have exclusive control over this submission via my password.
By including this header comment, I certify that:
1) I have read and understood the policy on academic integrity.
2) I have completed Moodle's module on academic integrity.
3) I have achieved at least 80% on the academic integrity quiz
I assert that this work is my own. I have appropriate acknowledged
any and all material that I have used, be it directly quoted or
paraphrased. Furthermore, I certify that this assignment was written
by me in its entirety.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/givenA2.h"

//this function takes a filename as its only parameter and stores employee records in it
void createContacts (char * fileName);
void createContacts (char * fileName){

    FILE *fptr = fopen(fileName, "ab+"); //open file in append mode

    if (fptr == NULL){
        printf("File is either empty or cannot be opened.\n");
        return;
    }

    struct contact newContact;

    long currentPosition = ftell(fptr);

    if (currentPosition == 0) {
        //seek to the beginning of the file
        fseek(fptr, 0, SEEK_SET);
    } else {
        //move to the end
        fseek(fptr, 0, SEEK_END);
    }
    
    //ask for user input
    int employeeId;
    printf("Employee id: \n");
    scanf("%d", &employeeId);
    char firstName[100];
    printf("First Name: \n");
    scanf("%s", firstName);
    char lastName[100];
    printf("Last Name: \n");
    scanf("%s", lastName);
    char email[100];
    printf("Email: \n");
    scanf("%s", email);

    //get to the current position of the file pointer
    fseek(fptr, 0, SEEK_END);


    //add contacts based on position
    newContact.empIdPosn = ftell(fptr) + sizeof(struct contact);
    newContact.firstNamePosn = newContact.empIdPosn + (sizeof(int));
    newContact.lastNamePosn = newContact.firstNamePosn + (strlen(firstName) + 1);
    newContact.emailPosn = newContact.lastNamePosn + (strlen(lastName) + 1);
    newContact.next = newContact.emailPosn + (strlen(email) + 1);
    

    //write the new contact into the file
    fwrite(&newContact, sizeof(struct contact), 1, fptr);

    
    //allocate space for inputs
    char *firstNameEntered;
    char *lastNameEntered;
    char *emailEntered;
    firstNameEntered = malloc(sizeof(char) * (strlen(firstName) + 1));
    lastNameEntered = malloc(sizeof(char)* (strlen(lastName) + 1));
    emailEntered = malloc(sizeof(char) * (strlen(email) + 1));


    //copy the string into allocated memory
    strcpy(firstNameEntered, firstName);
    strcpy(lastNameEntered, lastName);
    strcpy(emailEntered, email);

    //write it to the file
    fwrite(&employeeId, sizeof(int), 1, fptr);
    fwrite(firstNameEntered, sizeof(char), (strlen(firstName) + 1), fptr);
    fwrite(lastNameEntered, sizeof(char), (strlen(lastName) + 1), fptr);
    fwrite(emailEntered, sizeof(char), (strlen(email) + 1), fptr);

    free(firstNameEntered);
    free(lastNameEntered);
    free(emailEntered);

    //close the file
    fclose(fptr);

}