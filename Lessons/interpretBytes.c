#include <stdio.h>

int main ( ) 
{
   int num = 5263;
   char a, b, c, d;
   
   FILE *fptr;
   fptr = fopen ( "testme", "w" );
   fprintf (fptr, "%d", num);
   fclose ( fptr );
   
   fptr = fopen ( "testme", "r" );
   fscanf ( fptr, "%d", &num );
   printf ( "Number = %d\n", num );
   fclose ( fptr );
   
   fptr = fopen ( "testme", "r" );
   fscanf (fptr, "%c%c%c%c",&a, &b, &c, &d);
   printf ("%c   %c   %c    %c\n", a, b, c, d);
   fclose (fptr);
   
   return(0);
}
