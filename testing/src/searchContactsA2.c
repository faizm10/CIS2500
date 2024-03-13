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

//this function takes a filename and an int value for employee id, searches for that id, prints the employee
//record and returns 1 if found, does not print anything and returns 0 if not found*
int searchContacts (char * fileName, int keyId);
int searchContacts (char * fileName, int keyId){

    FILE *fptr = fopen(fileName, "a+");

    if (fptr == NULL){
        printf("File cannot open.\n");
        return -1;
    }
    
    typedef struct contact readContact;
    readContact currentContact;

    while (fread(&currentContact, sizeof(struct contact), 1, fptr) == 1){

        //allocate space to store each contact
        int empId;

        //statically allocate space
        char firstName[100];
        char lastName[100];
        char email[100];

        //read employee id, move pointer to this position
        fseek(fptr, currentContact.empIdPosn, SEEK_SET);
        fread(&empId, sizeof(int), 1, fptr);

        if (empId == keyId) {   //if true, read the rest of the values

            //read first name
            fseek(fptr, currentContact.firstNamePosn, SEEK_SET);
            fread(firstName, (sizeof(char)), (currentContact.lastNamePosn - currentContact.firstNamePosn), fptr);

            //read last name
            fseek(fptr, currentContact.lastNamePosn, SEEK_SET);
            fread(lastName, (sizeof(char)), (currentContact.emailPosn - currentContact.lastNamePosn), fptr);

            //read email
            fseek(fptr, currentContact.emailPosn, SEEK_SET);
            fread(email, (sizeof(char)), (currentContact.next - currentContact.emailPosn), fptr);

            //print these details
            printf("****************************\n");
            printf("Employee ID: %d\n", empId);
            printf("First Name: %s\n", firstName);
            printf("Last Name: %s\n", lastName);
            printf("Email: %s\n", email);
            printf("****************************\n");
            fclose(fptr);

            return 1; // Found, return 1
        } else {
            //if empId does not equal keyId, move the pointer to the next contact
            fseek(fptr, currentContact.next, SEEK_SET);
        }
    }

    //if we reach this point, it means the contact was not found.

    fclose(fptr);

    return 0; 

}