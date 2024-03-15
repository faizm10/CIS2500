// secondEx.c 

#include <stdio.h>

int add (int, int);
int sub (int, int);
int mul (int, int);

int main () {
    
    int ans;
    int choice;
    
    // declare an array of function pointers - and initialize the array with functions add, sub and mul
    // analogy - int arr [3] = {1,2,3};
    int (*fun [3]) (int, int) = {add, sub, mul};
    
    printf ("Would you like to add (1), sub (2), mul (3)?");
    scanf ("%d", &choice);
    
    ans = fun [choice - 1] (3, 10);          // same as ans = (*fun [choice - 1]) (3, 10)
    
    printf ("%d \n", ans);
    return 0;
}

int add (int a, int b){
    
    return a + b;
}

int sub (int a, int b){
    
    return a - b;
}

int mul (int a, int b){
    
    return a * b;
}
