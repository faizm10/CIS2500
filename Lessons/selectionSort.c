#include <stdio.h>
#define SIZE 10
/* selection sort*/

void printArray (int array [SIZE]);
void selectionSort (int array [SIZE]);

int main() {
    int array[10] = {2, 10, -2, 3, 40, 5, 99, 11, 34, 8};
   // {1,2,3,4,5,6,7,8,9,10};
   
    printf ("Before Sorting using selection sort :\n");
    printArray (array);
    
    selectionSort (array);
    
    printf ("After Sorting :\n");
    printArray (array);
    
    return 0;
}

void printArray (int array [SIZE]) {
   
   int i;
   
   for (i = 0; i < SIZE; i++) {
      printf("%d ", array[i]);
   }
   printf ("\n");
}

void selectionSort (int array [SIZE]) {
   
   int i, j, minVal, minPos;
   int temp;
   
   for (i = 0; i < SIZE - 1; i++) {
      minVal = array[i];
      minPos = i;
      for (j = i + 1; j < SIZE; j++) {
         
         if (array [j] < minVal) {
            minPos = j;
            minVal = array [j];
         }
      }
      
      temp = array [i];
      array [i] = array [minPos];
      array [minPos] = temp;
    
   }
}


