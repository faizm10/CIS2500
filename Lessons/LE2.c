#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct tag
{
    int stack[MAX]; // stack
    int top;        // top of the stack
};

typedef struct tag Stack;

int pop(Stack *s);
void push(int element, Stack *s);
void printStack(Stack s);

int main()
{
    Stack myStack;
    myStack.top = -1;
    // Pushing elements to the stack in a specific order
    //push(5, &myStack); // Push 5
    int value;

    // Input MAX values into myStack
    for (int i = 0; i < MAX; i++)
    {
        printf("Enter value for element %d: ", i);
        scanf("%d", &value);
        push(value, &myStack);
    }

    // Print original stack for testing purposes
    printf("Original stack:\n");
    printStack(myStack);

    // Using two temporary stacks to remove even elements
    Stack temp1, temp2;
    temp1.top = temp2.top = -1;

    // Transfer all elements from myStack to temp1, skipping even numbers
    while (myStack.top != -1)
    {
        int element = pop(&myStack);
        if (element % 2 != 0)
        { // Check if the element is odd
            push(element, &temp1);
        }
        else
        {
            push(element, &temp2); // Keep even numbers in temp2, in case we need them
        }
    }

    // Transfer back all elements from temp1 to myStack
    while (temp1.top != -1)
    {
        push(pop(&temp1), &myStack);
    }

    // Print stack after removing even elements
    printf("Stack after removing even elements:\n");
    printStack(myStack);

    return 0;
}

void push(int element, Stack *s)
{
    if (s->top < MAX - 1)
    { // Ensure we don't overflow the stack
        s->top = s->top + 1;
        s->stack[s->top] = element;
    }
    else
    {
        printf("Stack overflow!\n");
    }
}

int pop(Stack *s)
{
    if (s->top >= 0)
    { // Ensure we don't pop from an empty stack
        int element = s->stack[s->top];
        s->top = s->top - 1;
        return element;
    }
    else
    {
        printf("Stack underflow!\n");
        return -1; // Return an invalid value to indicate underflow
    }
}

void printStack(Stack s)
{
    int num = s.top;

    for (int i = num; i >= 0; i--)
    {
        printf("Element %d : %d \n", i, s.stack[i]);
    }
}
