#include "givenA1.h"

int main() {
    struct Animal dataZoo[NUM_SAMPLES];
    struct Animal testData[NUM_TEST_DATA];
    char fileName[30] = "a1Data.txt";
    int readResult = readFromFile(fileName, dataZoo);
    
    // Read training data
    if (readResult == -1) {
        printf("Error reading training data from file. Exiting program.\n");
        return -1;
    }

    printf("Success\n");

    // Sample vectors and arrays
    int vectorA[NUM_FEATURES] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0};
    int vectorB[NUM_FEATURES] = {0, 1, 1, 0, 1, 0 ,0, 0, 1, 1, 0 ,0 ,2, 1, 0 ,0};
    int sample4[NUM_FEATURES] = {1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1};
    int sample2[NUM_SAMPLES] = {8, 12, 24, 39, 55};
    int choice;
    int k = 5;

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Generate Statistics for a Specific Feature\n");
        printf("2. Class Distribution\n");
        printf("3. Euclidean Distance\n");
        printf("4. Hamming Distance\n");
        printf("5. Jaccard Similarity\n");
        printf("6. Find k-Nearest Neighbors\n");
        printf("7. Predict Class\n");
        printf("8. Find Accuracy\n");
        printf("0. Exit\n");

        // Prompt user for choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform task based on user's choice
        switch (choice) {
            case 1: {
                // Task 2: Generate statistics for a specific feature
                int whichFeature;
                float mean;
                int mode;

                printf("Enter the feature number (1-16) to generate statistics: ");
                scanf("%d", &whichFeature);

                int statResult = generateStatisticsFeatureX(dataZoo, whichFeature, &mean, &mode);

                if (statResult == -1) {
                    printf("Invalid feature number.\n");
                } else {
                    printf("Mean: %f\n", mean);
                    printf("Mode: %d\n", mode);
                }
                break;
            }
            case 2:
                // Task 3: Class distribution
                classDistribution(dataZoo);
                break;
            case 3:
                // Task 4: Euclidean distance
                printf("Euclidean Distance: %0.2f\n", (euclideanDistance(vectorA, vectorB)));
                break;
            case 4:
                // Task 5: Hamming distance
                printf("Hamming Distance: %d\n", (hammingDistance(vectorA, vectorB)));
                break;
            case 5:
                // Task 6: Jaccard similarity
                printf("Jaccard Similarity: %0.2f\n", jaccardSimilarity(vectorA, vectorB));
                break;
            case 6:
                // Task 7: Find k-nearest neighbors
                printf("Please enter k: \n");
                scanf("%d", &k);
                int d = 0;
                printf("Please enter which distance formula: \n");
                scanf("%d", &d);
                int kNearestNeighbors[NUM_SAMPLES];
                findKNearestNeighbors(dataZoo, sample4, k, d, kNearestNeighbors);
                printf("KNearestNeighbors: \n");
                for (int i = 0; i < k; i++) {
                    printf("%d \n", kNearestNeighbors[i]);
                }
                break;
            case 7:
                printf("Predicted Class: %d\n", predictClass(dataZoo, sample2, sample4, k));
                break;
            case 8: {
                FILE *testDataFile = fopen("testData.csv", "r");
                if (testDataFile == NULL){
                    printf("Could not open testData.csv.\n");
                    exit(EXIT_FAILURE);
                }

                // Read data from file and store it in the testData array
                for (int i = 0; i < NUM_TEST_DATA; i++){
                    // Read an entire line
                    char line[256]; // Assuming a maximum line length of 255 characters
                    if (fgets(line, sizeof(line), testDataFile) == NULL){
                        printf("Error reading line %d from testData.csv.\n", i + 1);
                        fclose(testDataFile);
                        exit(EXIT_FAILURE);
                    }
                    // Use sscanf to parse the line
                    if (sscanf(line, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
                               testData[i].animalName, &testData[i].features[0], &testData[i].features[1],
                               &testData[i].features[2], &testData[i].features[3], &testData[i].features[4],
                               &testData[i].features[5], &testData[i].features[6], &testData[i].features[7],
                               &testData[i].features[8], &testData[i].features[9], &testData[i].features[10],
                               &testData[i].features[11], &testData[i].features[12], &testData[i].features[13],
                               &testData[i].features[14], &testData[i].features[15], &testData[i].classLabel) != NUM_FEATURES + 2){
                        printf("Error parsing line %d.\n", i + 1);
                        fclose(testDataFile);
                        exit(EXIT_FAILURE);
                    }
                }
                fclose(testDataFile);
                k=57;
                printf("Accuracy: %.2f%%\n", findAccuracy(dataZoo, testData, k));
                break;
            }
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 0 and 8.\n");
        }
    } while (choice != 0);
    
    return 0;
}
