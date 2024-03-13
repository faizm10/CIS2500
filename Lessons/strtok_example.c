#include <stdio.h>
#include <string.h>


int main() {
   char st1[] = "CIS2500 is fun";
   char st2 [] = "CIS1300,CIS2500,CIS2520"; 

   char *resultSt1[3];

   // strtok used with space as a token
   resultSt1[0] = strtok(st1, " ");
   resultSt1[1] = strtok(NULL, " ");
   resultSt1[2] = strtok(NULL, " ");

   printf("%s\n%s\n%s\n", resultSt1[0], resultSt1[1], resultSt1[2]);

   // strtok used with comma as a token
   resultSt1[0] = strtok(st2, ",");
   resultSt1[1] = strtok(NULL, ",");
   resultSt1[2] = strtok(NULL, ",");

   printf("%s\n%s\n%s\n", resultSt1[0], resultSt1[1], resultSt1[2]);

   return 0;
}
