#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct tag {
    
    int stack[MAX];
    int top;
    
};

typedef struct tag Stack;

int pop (Stack * s);
void push (int element, Stack * s);
void printStack (Stack s);

int main () {

   Stack myStack;
   
   myStack.top = -1;

   
   
   
   
   
   
   
   //printStack(myStack);
   return 0;
}

void push (int element, Stack * s ) {
        
    s->top = s->top + 1;
    s->stack[s->top] = element;
    
}

int pop (Stack * s) {
    
    int element;
    
    element = s->stack [s->top];
    s->top = s->top - 1;
    
    return element;
    
}

void printStack (Stack s) {
   
   int num = s.top;
   
   printf ("\nPrinting the stack with topmost element first\n");
   
   for (int i = num; i >= 0; i--) {
      
      printf ("Element %d : %d \n", i, pop (&s));
   }
}
