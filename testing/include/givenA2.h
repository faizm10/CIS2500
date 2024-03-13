#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
I assert that this work is my own. I have appropriate acknowledged
any and all material that I have used, be it directly quoted or
paraphrased. Furthermore, I certify that this assignment was written
by me in its entirety.
*/

struct contact {
   long empIdPosn;
   long firstNamePosn;
   long lastNamePosn;
   long emailPosn;
   long next;
};
/* this function takes a filename as its only parameter and stores employee records in it*/
void createContacts (char * fileName);
/* this function takes a filename as its only parameter and prints all employee records stored in it in the
same sequence as it was created*/
void readContacts (char * fileName);
/* this function takes a filename and an int value for employee id, searches for that id, prints the employee
record and returns 1 if found, does not print anything and returns 0 if not found*/
int searchContacts (char * fileName, int keyId);
