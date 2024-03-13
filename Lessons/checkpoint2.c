//Week 5 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{ 
   char *name, *ptr;
   int i;
   name = malloc ( sizeof(char) * 10 );
   strcpy (name, "abcdefg");
   
   // name = "abcdefg";
   
   ptr = name;
   
   for ( i=0; i < strlen (name) ; i++ ) {
      printf ( "%c\n", *name );
      name++;
   }
 
  
  return 0;
}




