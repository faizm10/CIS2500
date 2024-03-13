#include <stdio.h>
#include <string.h>

/*
 This function findLen finds the length of a given string recursively
 */

//int findLen (char n [], int);

int findLen (char * n);

int main () {

   char str [50];
   
   fgets (str, 50, stdin);
   str [strlen (str) - 1] = '\0';
   
   int len = findLen (str);
   
   printf ("Length of %s = %d\n", str, len);
}

int findLen (char * n) {
   
   if (*n == '\0') {
      return 0;
   }
   else {
      return 1 + findLen (n + 1);
   }
}

/*

int findLen (char str[], int n) {
    
    int len;
    
    if (n == 0) {
        len = 0;
    }
    else {
        len = 1 + findLen (str, n-1);
    }
    return len;
}
*/
