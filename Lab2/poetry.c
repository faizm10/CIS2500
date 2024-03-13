#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_LINE_LENGTH 100

// Function prototypes
void processPoem(FILE *file);

// Main function
int main(int argc, char *argv[]) {
    // Check for correct command-line arguments
    if (argc != 2) {
        printf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the file
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    // Process the poem
    processPoem(file);

    // Close the file
    fclose(file);

    return 0;
}

// Function to process the poem
void processPoem(FILE *file) {
    char *line = NULL;
    size_t lineLength = 0;
    ssize_t bytesRead;
    int totalWords = 0;
    int totalLines = 0;

    int *wordsPerLine = NULL;
    size_t wordsArraySize = 2;  // Initial size

    // Allocate memory for the array
    wordsPerLine = malloc(wordsArraySize * sizeof(int));
    if (!wordsPerLine) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    // Read lines from the file
    while ((bytesRead = getline(&line, &lineLength, file)) != -1) {
        // Remove newline character if neccessary
        if (line[bytesRead - 1] == '\n') {
            line[bytesRead - 1] = '\0';
        }

        // break down the line into words
        char *token = strtok(line, " ");
        int wordsInLine = 0;

        // Count words in the line
        while (token != NULL) {
            totalWords++;
            wordsInLine++;
            token = strtok(NULL, " ");
        }

        // Resize the array if neccessary
        if (totalLines >= wordsArraySize) {
            wordsArraySize *= 2;
            wordsPerLine = realloc(wordsPerLine, wordsArraySize * sizeof(int));
            if (!wordsPerLine) {
                perror("Error reallocating memory");
                exit(EXIT_FAILURE);
            }
        }

        // Store the number of words in the current line
        wordsPerLine[totalLines] = wordsInLine;
        totalLines++;
    }

    // Print results
    printf("%d word%s on %d line%s\n", totalWords, totalWords == 1 ? "" : "s", totalLines, totalLines == 1 ? "" : "s");

    // Print the number of words on each line
    for (int i = 0; i < totalLines; i++) {
        printf("%d%c", wordsPerLine[i], (i == totalLines - 1) ? '\n' : ' ');
    }

    // Free allocated memory
    free(line);
    free(wordsPerLine);
}
