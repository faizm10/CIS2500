#include <stdio.h>
#include <string.h>

int main () 
{
   struct info {
      char name[10];
      int  id;
   };

   typedef struct info record;
   
   record item;
   record newItem[10];

   FILE *fptr;
   int i;
    
   char names[10][40] = {"Fred","John","Mary","Ford","Gert","Hamm","Will","Bill","Paul","Samm"};

   fptr = fopen ( "data", "w+" );
   for ( i=0; i<10; i++ ) {
      strcpy ( item.name, names[i]);
      item.id = i;
      fwrite ( &item, sizeof(item), 1, fptr );
   }
   
   // TO DO
   
   return 0;
}
