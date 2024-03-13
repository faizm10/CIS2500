#include <stdio.h>
#include <stdlib.h>
#define MAX 6

// Implementing Stacks using arrays

typedef struct {
    
    int stack[MAX];          // stack as an array
    int top;                 // top of the stack
    
} Stack;

int pop (Stack * s);
void push (int element, Stack * s);
int peek (Stack s);
int isEmpty (Stack s);        // if s.top == -1, stack is empty
Stack stackCreate (void);

int main () {
    
    Stack s;           // declare a stack variable
    //int element;
    
    s = stackCreate ();          // create an empty stack
    
    /* pushing 4 elements onto stack s*/
    push (3, &s);
    push (4, &s);
    push (10, &s);
    push (20, &s);
    
    printf ("Popping the top 2 elements:");
    printf ("%d %d\n", pop(&s), pop(&s));
    
    printf ("Peeking into the current top element:");
    printf ("%d \n", peek (s));
   
   printf ("Is stack empty? ");
   if (isEmpty(s)) {
      printf ("Yes, it is.\n");
   }
   else {
      printf ("No, it is not. It has %d elements\n", s.top+1);
   }
    
}

/*this function pushes an element to stack s
 Note that the stack is passed-by-reference because pushing an element
 will not only add the element to the top of the stack, but also change
 the top of the stack */

void push (int element, Stack * s ) {
        
    s->top = s->top + 1;
    s->stack[s->top] = element;
    
}

/*this function removes the top element from stack s
 Note that the stack is passed-by-reference because popping an element
 will not only remove the top element of the stack, but also change
 the top of the stack */

int pop (Stack * s) {
    
    int element;
    
    element = s->stack [s->top];
    s->top = s->top - 1;
    
    return element;
    
}

/*this function returns the top element ofstack s
 */
int peek (Stack s) {
    
    return s.stack [s.top];
}

Stack stackCreate (void) {

    Stack s;

    s.top = -1;    // empty stack
    return s;
}

int isEmpty (Stack s) {
   
   return s.top == -1; // empty stack
   // one of you suggested s->top < 0 in the mornign class, which is also fine, and safer perhaps
}

