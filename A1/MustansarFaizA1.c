#include "givenA1.h"

// Reads animal data from a file and populates the dataZoo array.
int readFromFile(char fName[30], struct Animal dataZoo[NUM_SAMPLES]){
    FILE *file = fopen(fName, "r");

    if (file == NULL){
        return -1; // File not found or unable to open
    }

    // Loop to read each line from the file
    for (int i = 0; i < NUM_SAMPLES; i++){
        if (fscanf(file, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
                   dataZoo[i].animalName,
                   &dataZoo[i].features[0], &dataZoo[i].features[1], &dataZoo[i].features[2],
                   &dataZoo[i].features[3], &dataZoo[i].features[4], &dataZoo[i].features[5],
                   &dataZoo[i].features[6], &dataZoo[i].features[7], &dataZoo[i].features[8],
                   &dataZoo[i].features[9], &dataZoo[i].features[10], &dataZoo[i].features[11],
                   &dataZoo[i].features[12], &dataZoo[i].features[13], &dataZoo[i].features[14],
                   &dataZoo[i].features[15]) != 17){
            // Error reading line from the file
            printf("Error reading line %d from file.\n", i + 1);
            fclose(file);
            return -1;
        }

        // Read the class label
        if (fscanf(file, "%d", &dataZoo[i].classLabel) != 1){
            // Error reading class label
            printf("Error reading class label for line %d from file.\n", i + 1);
            fclose(file);
            return -1;
        }
    }

    fclose(file);
    return 1; // Successful operation
}


// Generates statistics (mean and mode) for a specific feature.
int generateStatisticsFeatureX(struct Animal dataZoo[NUM_SAMPLES], int whichFeature, float *mean, int *mode) {
    // Validate the feature number
    if (whichFeature < 1 || whichFeature > 16) {
        // Incorrect feature number
        return -1;
    }

    int count = 0;
    int modeCount = 0;
    int currentMode = -1;
    int occurrences[NUM_SAMPLES] = {0};

    // Calculate count, modeCount, currentMode, and occurrences
    for (int i = 0; i < NUM_SAMPLES; i++) {
        count += dataZoo[i].features[whichFeature - 1];
        occurrences[dataZoo[i].features[whichFeature - 1]]++;

        if (occurrences[dataZoo[i].features[whichFeature - 1]] > modeCount) {
            modeCount = occurrences[dataZoo[i].features[whichFeature - 1]];
            currentMode = dataZoo[i].features[whichFeature - 1];
        }
    }

    // Calculate mean, set mean and mode pointers
    *mean = (float)count / NUM_SAMPLES;
    *mode = currentMode;

    return 0; // Successful execution
}


// Displays the distribution of class labels in a vertical histogram.
void classDistribution(struct Animal dataZoo[NUM_SAMPLES]){
    int totalClasses[NUM_CLASSES] = {0}; // Array to store frequency of class labels

    // Count the occurrences of each class label
    for (int i = 0; i < NUM_SAMPLES; i++){
        int classLabel = dataZoo[i].classLabel;
        if (classLabel >= 1 && classLabel <= NUM_CLASSES){
            totalClasses[classLabel - 1]++;
        }
    }

    // Find the maximum frequency to determine the position of the max count
    int maximumCount = 0;
    for (int i = 0; i < NUM_CLASSES; i++){
        if (totalClasses[i] > maximumCount){
            maximumCount = totalClasses[i];
        }
    }

    // Display the class distribution as a vertical histogram with max counts on top
    for (int level = maximumCount; level > 0; level--){
        for (int i = 0; i < NUM_CLASSES; i++){
            if (totalClasses[i] >= level){
                if (totalClasses[i] == level){
                    printf("(%d)\t", totalClasses[i]);
                }
                else{
                    printf(" \t");
                }
            }
            else{
                printf(" \t");
            }
        }
        printf("\n");
        //Prints Stars
        for (int i = 0; i < NUM_CLASSES; i++){
            if (totalClasses[i] >= level){
                printf("*\t");
            }
            else{
                printf(" \t");
            }
        }
        printf("\n");
    }

    // Display the class labels on the x-axis
    for (int i = 0; i < NUM_CLASSES; i++){
        printf("Class%d\t", i + 1);
    }
    printf("\n");
}

// Calculates the Euclidean distance between two vectors.
float euclideanDistance(int vector1[NUM_FEATURES], int vector2[NUM_FEATURES]) {
    float total = 0;
    for (int i = 0; i < NUM_FEATURES; i++) {
        total += ((vector1[i] - vector2[i]) * (vector1[i] - vector2[i]));
    }
    total = sqrt(total);
    return total;
}

// Calculates the Hamming distance between two vectors.
int hammingDistance(int vector1[NUM_FEATURES], int vector2[NUM_FEATURES]) {
    int count = 0;
    for (int i = 0; i < NUM_FEATURES; i++) {
        if (vector1[i] != vector2[i]) {
            count++;
        }
    }
    return count;
}

// Calculates the Jaccard similarity between two vectors.
float jaccardSimilarity(int vector1[NUM_FEATURES], int vector2[NUM_FEATURES]) {
    int count0 = 0, count1 = 0;
    for (int i = 0; i < NUM_FEATURES; i++) {
        if (vector1[i] == 1 && vector2[i] == 1) {
            count1++;
        } else if (vector1[i] == 0 && vector2[i] == 0) {
            count0++;
        }
    }
    float total = (float)count1 / (NUM_FEATURES - count0);
    return total;
}

//citation: https://www.javatpoint.com/bubble-sort-program-in-c
void findKNearestNeighbors(struct Animal dataZoo[NUM_SAMPLES], int newSample[NUM_FEATURES], int k, int whichDistanceFunction, int kNearestNeighbors[NUM_SAMPLES]) {
    double distances[NUM_SAMPLES];
    // Calculate distances based on the selected distance function
    for (int i = 0; i < NUM_SAMPLES; ++i) {
        double euclidean = euclideanDistance(dataZoo[i].features, newSample);
        double hamming = hammingDistance(dataZoo[i].features, newSample);
        double jaccard = jaccardSimilarity(dataZoo[i].features, newSample);
        
        switch (whichDistanceFunction) {
            case 1:  // Euclidean
                distances[i] = euclidean;
                break;
            case 2:  // Hamming
                distances[i] = hamming;
                break;
            case 3:  // Jaccard
                distances[i] = jaccard;
                break;
            default:
                break;
        }
        kNearestNeighbors[i] = i;  // Initialize indices
    }
    // Sort distances and indices in ascending order using bubble sort
    for (int i = 0; i < NUM_SAMPLES - 1; ++i){
        for (int j = 0; j < NUM_SAMPLES - i - 1; ++j){
            if (distances[j] > distances[j + 1]){
                // Swap distances[j] and distances[j+1]
                double tempDistance = distances[j];
                distances[j] = distances[j + 1];
                distances[j + 1] = tempDistance;

                // Swap kNearestNeighbors[j] and kNearestNeighbors[j+1]
                int tempIndex = kNearestNeighbors[j];
                kNearestNeighbors[j] = kNearestNeighbors[j + 1];
                kNearestNeighbors[j + 1] = tempIndex;
            }
        }
    }
    // Keep only the first K indices
    for (int i = 0; i < k; ++i){
        kNearestNeighbors[i] = kNearestNeighbors[i];
    }
}
int predictClass (struct Animal dataZoo [NUM_SAMPLES], int neighborsForNewSample [NUM_SAMPLES], int newSample [NUM_FEATURES], int k) {
   // Count occurrences of each class label among the neighbors
    int classCounts[NUM_SAMPLES] = {0};  // Assuming there are 7 unique class labels (1 to 7)
    for (int i = 0; i < k; i++) {
        int neighborIndex = neighborsForNewSample[i];
        int neighborClass = dataZoo[neighborIndex].classLabel;
        classCounts[neighborClass - 1]++;  // Class labels start from 1, so subtract 1 to adjust array index
    }

    // Find the class label with the highest count
    int maxCount = 0;
    int predictedClass = 0;
    for (int i = 0; i < NUM_SAMPLES; i++) {  // Assuming there are 7 unique class labels (1 to 7)
        if (classCounts[i] > maxCount) {
            maxCount = classCounts[i];
            predictedClass = i + 1;  // Add 1 to adjust for class labels starting from 1
        }
    }

    return predictedClass;
}

// Calculates the accuracy of the k-nearest neighbors algorithm on a test dataset.
float findAccuracy(struct Animal dataZoo[NUM_SAMPLES], struct Animal testData[NUM_TEST_DATA], int k){
    int correctPredictions = 0;

    // Iterate through each sample in testData.csv
    for (int i = 0; i < NUM_TEST_DATA; i++){
        int prediction;
        int kNearestNeighbors[NUM_SAMPLES];

        // Use k-nearest-neighbor algorithm to predict the class
        findKNearestNeighbors(dataZoo, testData[i].features, k, 1, kNearestNeighbors);
        prediction = predictClass(dataZoo, kNearestNeighbors, testData[i].features, k);

        // Check if the prediction is accurate
        if (prediction == testData[i].classLabel){
            correctPredictions++;
        }
    }

    // Calculate the accuracy:
    float accuracy = (float)correctPredictions / NUM_TEST_DATA * 100.0;

    return accuracy;
}
