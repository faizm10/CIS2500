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

//this function takes a filename as its only parameter and prints all employee records stored in it in the
//same sequence as it was created
void readContacts (char * fileName);
void readContacts (char * fileName){

    FILE *fptr = fopen(fileName, "r");

    if (fptr == NULL){
        printf("File cannot be opened.\n");
        return;
    }


    typedef struct contact readContact;
    readContact currentContact;


    while (fread(&currentContact, sizeof(struct contact), 1, fptr) == 1) {
        //allocate space to store each contact
        int empId;

        //statically allocate space
        char firstName[100];
        char lastName[100];
        char email[100];

        //read employee id
        fseek(fptr, currentContact.empIdPosn, SEEK_SET);
        fread(&empId, sizeof(int), 1, fptr);

        //read first name
        fseek(fptr, currentContact.firstNamePosn, SEEK_SET);
        fread(firstName, (sizeof(char)), (currentContact.lastNamePosn - currentContact.firstNamePosn), fptr);

        //read last name
        fseek(fptr, currentContact.lastNamePosn, SEEK_SET);
        fread(lastName, (sizeof(char)), (currentContact.emailPosn - currentContact.lastNamePosn), fptr);

        //read email
        fseek(fptr, currentContact.emailPosn, SEEK_SET);
        fread(email, (sizeof(char)), (currentContact.next - currentContact.emailPosn), fptr);


        //print details
        printf("****************************\n");
        printf("Employee ID: %d\n", empId);
        printf("First Name: %s\n", firstName);
        printf("Last Name: %s\n", lastName);
        printf("Email: %s\n", email);
        printf("****************************\n");
        printf("\n");
    

        //update the pointer
        fseek(fptr, currentContact.next, SEEK_SET);
    
    }

   fclose(fptr);
}