#include <stdio.h>

int add (int, int);
int sub (int, int);
int mul (int, int);

int main () {

   int ans;
   int choice = 3;
   
   // declare a function pointer fun
   int (* fun) (int, int); 

   switch (choice) {
       case 1: fun = &add;
           break;
       case 2: fun = &sub;
           break;
       case 3: fun = &mul;
           break;
   }

   ans = (*fun) (4, 10);
   printf ("%d \n", ans);

}

int add (int a, int b) {

    return a + b;
}

int sub (int a, int b) {

    return a - b;
}

int mul (int a, int b) {

    return a * b;
}