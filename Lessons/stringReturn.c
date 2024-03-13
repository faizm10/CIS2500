// Different ways to return strings from functions
// Note that fun2 does not do its job

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

char * fun1 (void);
char * fun2 (void);
char * fun3 (void);
void fun4 (char *);

int main()
{ 
  
   char * str1 = fun1 ();
   printf ("Fun1 returns %s \n", str1);
   
   char * str2 = fun2 ();
   printf ("Fun2 returns %s \n", str2);
   
   char * str3 = fun3 ();
   printf ("Fun3 returns %s \n", str3);
   
   char str4 [100];
   fun4 (str4);
   printf ("Fun4 returns %s \n", str4);
   

   return 0;
}

char * fun1 (void) {
   
   return "Ending fun1";
}

char * fun2 (void) {
   
   char localStr [] = "Declared in fun2";
   
   return localStr;
}

char * fun3 (void) {
   
   char * localStr = malloc (sizeof (char) * (strlen("Declared in fun3") + 1));
   
   strcpy (localStr, "Declared in fun3");
   
   return localStr;
}

void fun4 (char * st) {
   
   strcpy (st, "We know this one\n");
}
