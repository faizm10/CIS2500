//Week 5 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{ 
   char *name, *ptr;
   int i;
   
   name = malloc ( sizeof(char) * 10 );
   
   printf ("Address after malloc %p\n", name);
   
   name = "abcdefg";
   
   printf ("Address after assignment %p\n", name);
   
   ptr = name;
   for ( i=0; i<strlen (name); i++ ) {
      printf ( "%c\n", *ptr );
      ptr++;
   }
   
  
  return 0;
}




