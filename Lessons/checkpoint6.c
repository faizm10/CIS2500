//Week 5 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() { 
  int arr [3][5] = { {1, 2, 13, 14, 5}, 
                     {6, 7, 8, 9, 10},
                     {11, 12, 13, 14, 15}
                   };
  int i = 0;
  int * ptr = &arr[0][0];
  
  printf ("%d \n", *(ptr + 3));
  printf ("%d \n", *ptr + 2);
  printf ("%d \n", *(ptr + *(ptr + 2) + 1));
  
  return 0;
}



/*
 while (ptr != NULL) {
  
     printf ("%d Address: %p\n", *ptr, ptr);
     ptr++;
     i++;
  }
*/
