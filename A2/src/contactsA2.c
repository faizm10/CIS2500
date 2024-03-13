#include <stdio.h>
#include <stdlib.h>
#include "../include/givenA2.h"
#include <string.h>
#include <strings.h>
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
int main() {
    char fileName[] = "contactListA2.db"; 
    char userInput[10]; // To store user input for menu choices
    int choice;
    char answer[10];
    // beginning stage
    do
    {
        printf("Do you wish to enter a new contact (Yes or No)?: ");
        scanf("%s", answer);

        // if user input is no, move to the next stage
        if (strcasecmp(answer, "No") == 0)
        {
            break;
        }
        // if user input is yes, call createContacts function to create new record
        else if (strcasecmp(answer, "Yes") == 0)
        {
            createContacts(fileName);
        }
        // validation for input
        else
        {
            printf("Invalid input. Please enter 'Yes' or 'No'.\n");
        }
    } while (1);

    // Main menu for the application
    do {
        printf("\nEnter a choice:\n");
        printf("1 to print\n");
        printf("2 to search\n");
        printf("3 to create more\n");
        printf("-1 to exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                readContacts(fileName);
                break;
            case 2: {
                int searchId=0;
                do {
                    printf("Search for Employee Id? ");
                    scanf("%d", &searchId);
                } while (searchId < 1 || searchId > 9999); // ID Validation
                
                if (!searchContacts(fileName, searchId)) {
                    printf("No match found.\n");
                }
                break;
            }
            case 3:
                createContacts(fileName); //create new contacts
                break;
            case -1:
                printf("Exiting\n"); //exit program
                break;
            default:
                printf("Invalid choice. Please try again.\n"); //option validation
        }
    } while (choice != -1);//while menu options are valid

    return 0;
}
