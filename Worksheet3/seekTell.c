#include <stdio.h>
#include <string.h>

int main()
{
   struct info
   {
      char name[10];
      int id;
   };

   typedef struct info record;
   record item;
   record newItem[10];

   FILE *fptr;
   int i;
   int currentPosition;

   char names[10][40] = {"Fred", "John", "Mary", "Ford", "Gert", "Hamm", "Will", "Bill", "Paul", "Samm"};

   fptr = fopen("data", "w+");
   for (i = 0; i < 10; i++)
   {
      strcpy(item.name, names[i]);
      item.id = i;
      fwrite(&item, sizeof(item), 1, fptr);
   }

   fseek(fptr, 0, SEEK_SET);

   for (i = 0; i < 10; i++)
   {
      fread(&newItem[i], sizeof(record), 1, fptr);
   }

   for (i = 0; i < 10; i++)
   {
      printf("(%d) %s - %d\n", i + 1, newItem[i].name, newItem[i].id);
   }

   fseek(fptr, (sizeof(item) * 4), SEEK_SET);
   fread(&item, sizeof(item), 1, fptr);
   printf("Record 5: %s - %d\n", item.name, item.id);

   fseek(fptr, sizeof(item) * -3, SEEK_CUR);

   currentPosition = ftell(fptr);
   printf("Current position = %d\n", currentPosition);

   fread(&item, sizeof(item), 1, fptr);
   printf("Record 3: %s - %d\n", item.name, item.id);

   fseek(fptr, sizeof(item) * -2, SEEK_END);
   fread(&item, sizeof(item), 1, fptr);

   printf("Record: %s - %d\n", item.name, item.id);

   fclose(fptr);
   return 0;
}
