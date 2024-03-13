//Week 5 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{ 
  char *ptr1 = "Yoga";
  char *ptr2 = "Meditation";
  
  strcat (ptr2, ptr1);
  printf ("The concatenated string is %s\n", ptr2);
  
  return 0;
}




