
#include <stdio.h>
void printMe(int);
void printMeForClass ( int number );

int main () {
   
   // declare function ptr
   //int * ptrFun (int);     different meaning
   
   void (*ptrFun) (int);
   
   // assign it to a function with int parameter and void result
   
   ptrFun = &printMe;
   // dereference and call it - printMe (10);

  // printMe (10);  // direct
   (*ptrFun) (10);  // indirect call
   
   ptrFun = &printMeForClass;
   (*ptrFun) (10);
   
   return 0;
}


void printMeForClass ( int number ) {
   printf ("printMe: You passed me the number %d and I added 100 %d\n", number, number  +100 );
}

void printMe ( int number ) {
   printf ("printMe: You passed me the number %d\n", number);
}


