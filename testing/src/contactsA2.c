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
#include <string.h> // Include for strcmp function
#include "../include/givenA2.h"

int main(int argc, char * argv[]) {
    // First stage
    // Allocate space for yes or no
    char *answer = malloc(sizeof(char) * 5);

    while (1) {
        printf("Do you wish to enter a new contact (Yes or No)?: \n");
        scanf("%s", answer);
        if (strcmp(answer, "Yes") == 0) {
            // Call create contacts function
            createContacts(argv[1]);
        } else if (strcmp(answer, "No") == 0) {
            // Second stage
            int choice;
            printf("Menu: \n");
            printf("Enter a choice (1, 2, 3 or -1):\n");
            printf("1. print\n");
            printf("2. search\n");
            printf("3. create more\n");
            printf("-1. exit.\n");

            scanf("%d", &choice);

            int keyId; // Declare keyId outside the switch statement

            switch (choice) {
                case 1:
                    printf("Printing Employee records saved on file:\n");
                    // Read contacts
                    readContacts(argv[1]);
                    break;
                case 2:
                    // Prompt user for Employee Id
                    do {
                        printf("Search for Employee Id: \n");
                        scanf("%d", &keyId);
                        if (keyId < 1 || keyId > 9999) {
                            printf("Invalid input, keyId must be an integer between 1 and 9999.\n");
                            // Clear input buffer
                            while (getchar() != '\n');
                        }
                    } while (keyId < 1 || keyId > 9999);
                    // Search contacts
                    int result = searchContacts(argv[1], keyId);
                    if (result == 0) {
                        printf("No match found.\n");
                        return 0;
                    }
                    break;
                case 3:
                    // Call create contacts function
                    createContacts(argv[1]);
                    break;
                case -1:
                    printf("Exiting.\n");
                    return 0;
                default:
                    printf("Invalid choice. Please enter a valid option (1, 2, 3, or -1).\n");
            }
        } else {
            printf("Please enter Yes or No.\n");
            return -1;
        }
    }

    // Free allocated space
    free(answer);

    return 0;
}
