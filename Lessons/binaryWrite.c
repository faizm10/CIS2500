
//fwrite ( &num, sizeof(num),1, fptr );     // writes 1 integer in binary format


#include <stdio.h>
int main ( )
{
   int numArray[100], i;
   FILE *fptr;

   fptr = fopen ( "tmpfile", "w" );

   for ( i=0; i<100; i++ ) {
      
      numArray[i] = i;
   }
   
   fwrite ( numArray, sizeof(int), 100, fptr );

   fclose ( fptr );
}
