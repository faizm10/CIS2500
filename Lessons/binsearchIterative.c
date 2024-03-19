#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

int binsearch ( int *array, int size, int findMe);

int main ( )
{

   int arr[SIZE] = {-8, 4, 5, 6, 17,20, 39, 90};//{ 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
  
   int index = 0;
   
   int i;

   printf ( "Array to search: \n" );
   for ( i = 0; i < SIZE; i++ ) {
      printf ( "%d ", arr[i] );
   }
   printf ( "\n" );

   printf ( "Enter a key value to search, -1 to exit: " );
   scanf ( "%d", &i );
   
   while ( i >= 0 ) {
      index = binsearch ( arr, SIZE, i );
      printf ( "Element found at  index = %d\n", index );

      printf ( "Enter a key value to search, -1 to exit: " );
      scanf ( "%d", &i );
   }
   return (0);
}

int binsearch ( int *array, int size, int findMe ) {
   
   int left  = 0;
   int right = size - 1;
   int middle;
   
   while ( left <= right ) {
      middle = ( left + right ) / 2;
      if ( findMe == array [middle] ) {
         return ( middle );
      } else if ( findMe > array [middle] ) {
         left = middle + 1;
      } else {
         right = middle - 1;
      }
    
   }
   
   return ( -1 );
   
}
