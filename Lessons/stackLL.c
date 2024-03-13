/* Linked list implementation of Stack
 Note that comments are not given intentionally - its recommended that you read and understand this code, and add comments along the way
 */

#include <stdio.h>
#include <stdlib.h>

struct data {
    
    int elementStack;
    struct data * next;
};

typedef struct data * Stack;    // note that this typedef is different from the typdef used in stackArray.c

Stack stackCreate (void);
int pop (Stack * s);
void push (int element, Stack * s);
int peek (Stack s);
int isEmpty (Stack s);

int main () {

   Stack s;
   int element;
   s = stackCreate();
   
   push (10, &s);
   printf ("Pushed %d \n", s->elementStack);
   push (20, &s);
   printf ("Pushed %d \n", s->elementStack);
   push (30, &s);
   printf ("Pushed %d \n", s->elementStack);
   
   printf ("Peek #1: %d \n", peek (s));
   printf ("Peek #2: %d \n", peek (s));
   
   printf ("Popping all elements \n");
   while (s != NULL) {
     
      element = pop (&s);
      printf (" %d \n", element);
   }
    
   printf ("Is stack empty? ");
   if (isEmpty(s)) {
      printf ("Yes, it is.\n");
   }
   else {
      printf ("No, it is not.\n");
   }
   
   return 0;
}

Stack stackCreate (void) {
   
   Stack s = NULL;
   return s;
}

int isEmpty (Stack s) {
   
   return (s == NULL);
}

void push (int element, Stack * s) {

    Stack new = malloc (sizeof (Stack));

    if (*s == NULL) {    // first element of the stack
        new->next = NULL;
        new->elementStack = element;
        *s = new;
    }
    else {
        new -> elementStack = element;
        new -> next = *s;
        *s = new;
    }
   
}

int pop (Stack * s) {
 
    Stack temp = *s;
 
    int element = (*s)->elementStack;
    *s = (*s)->next;
 
   free (temp);
   return element;
    
}

int peek (Stack s) {
 
    int element = s->elementStack;
    
   return element;
    
}
