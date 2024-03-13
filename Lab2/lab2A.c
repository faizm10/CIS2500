// poetry.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_LINE_LENGTH 100

// Function to process the poem file
void processPoem(FILE *file);

int main(int argc, char *argv[]) {
    // Check if the correct number of command-line arguments is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the input file
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
void processPoem(FILE *file) {
    char *line = NULL;
    int lineLength = 0;
    int bytesRead;
    int totalWords = 0;
    int totalLines = 0;

    int *wordsPerLine = NULL;
    int wordsArraySize = 2;  // Initial size

    // Allocate memory for the array that stores words per line
    wordsPerLine = malloc(wordsArraySize * sizeof(int));
    if (!wordsPerLine) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    // Read lines from the file
    while ((bytesRead = getline(&line, &lineLength, file)) != -1) {
        // Remove newline character if present
        if (line[bytesRead - 1] == '\n') {
            line[bytesRead - 1] = '\0';
        }

        // Tokenize the line into words
        char *token = strtok(line, " ");
        int wordsInLine = 0;

        while (token != NULL) {
            totalWords++;
            wordsInLine++;
            token = strtok(NULL, " ");
        }

        // Resize the array if needed
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

        // Reset the wordsInLine counter for the next line
        wordsInLine = 0;
    }

    // Print the results
    printf("%d %s on %d %s\n", totalWords, (totalWords == 1) ? "word" : "words", totalLines, (totalLines == 1) ? "line" : "lines");

    // Print the number of words on each line
    for (int i = 0; i < totalLines; i++) {
        printf("%d%c", wordsPerLine[i], (i == totalLines - 1) ? '\n' : ' ');
    }

    // Free allocated memory
    free(line);
    free(wordsPerLine);
}
