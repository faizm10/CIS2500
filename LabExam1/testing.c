#include <stdio.h>
#include <stdlib.h>

// Function to populate the array
int* populateArray(int size) {
    int* arr = (int*) malloc (size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    return arr;
}
//searches for an value and returns it
//int searchValue(int* arr, int size, int target) {
//    for (int i = 0; i < size; i++) {
//        if (arr[i] == target) {
//            return i; // Return index if target value found
//        }
//    }
//    return -1; // Return -1 if target value not found
//}


// Function to find the maximum element in the array
//int findMax(int* arr, int size) {
//    int max = arr[0];
//    for (int i = 1; i < size; i++) {
//        if (arr[i] > max) {
//            max = arr[i];
//        }
//    }
//    return max;
//}



int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int* arr = populateArray(size);

    printf("Elements of the array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int evenCount = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evenCount++;
        }
    }
    printf("Number of even numbers: %d\n", evenCount);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}

