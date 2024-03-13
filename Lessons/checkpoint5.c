//Week 5 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{ 
  int arr [] = {0, 20, 30, 10, 50};
  int i = 0;
  
  for (i = 0; i < 5; i++) {
     printf ("%d\n", *(arr + i));
  }
  
    
  return 0;
}




