#include <stdio.h>
#define SIZE 10

int binaryR (int findMe, int arr [SIZE], int low, int high);

int main () {

   int foundIdx;
   int findMe;
   
   int arr [SIZE] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
   
   printf ( "Array to search: \n" );
   for ( int i = 0; i < SIZE; i++ ) {
      printf ( "%d ", arr[i] );
   }
   printf ( "\n" );

   printf ("Enter a key value to search, -1 to exit: ");
   scanf ("%d", &findMe);
   
   while (findMe != -1) {
      foundIdx = binaryR (findMe, arr, 1, SIZE);
      
      if (foundIdx != 0) {
            printf ("Element found at index %d\n", foundIdx);
      }
      else {
          printf ("Element not found\n");
      }
      
      printf ("Enter a key value to search, -1 to exit: ");
      scanf ("%d", &findMe);
   }

   return 0;
}

int binaryR (int findMe, int arr [SIZE], int low, int high) {

   int middle = (low + high) / 2;
   int found;
   
   if (low > high) {   // base case
      return 0;        // not found
   }
   
   else {            // base case
   		if (findMe == arr [middle]) {
   		   found = middle;
        }
        else if (findMe < arr [middle]) {
            found = binaryR (findMe, arr, low, middle - 1);
        }
        else {
        	found = binaryR (findMe, arr, middle + 1, high);
        }
        
        return found;
    }
}




