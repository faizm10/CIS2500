//Week 5 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROW 3
#define COL 5

int recurSumPtr (int * ptr, int n);
int main()
{ 
  int arr [ROW][COL] = { {1, 2, 13, 14, 5},
                     {6, 7, 8, 9, 10},
                     {11, 12, 13, 14, 25}
                   };
  int i = 0;
  int * ptr = &arr[0][0];
  
  int  sum = recurSumPtr (ptr, ROW * COL);
  printf ("Sum = %d\n", sum);
  
  return 0;
}

int recurSumPtr (int * ptr, int n) {
   
   if (n == 0) {         // base case
      return 0;
   }
   else {        // generic or recursive case
      
      return ptr [n - 1] + recurSumPtr ( ptr, n - 1);
   }
}
/* alternate solution
 
int recurSumPtr (int * ptr, int n) {
    
    if (n == 0) {
        return 0;
    }
    else {
        return *ptr + recurSumPtr (ptr+1, n-1);
    }
}

*/



















