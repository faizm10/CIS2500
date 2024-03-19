#include <stdio.h>

#define N 5
 
int lSearch(int arr[], int keyword);

int main(void)
{
    int arr[N] = { 2, 3, 4, 20, 40 };
    int keyword = 20;
    int found;
    
    found = lSearch(arr, keyword);
    
    if (found != -1) {
        printf ("Element found at index: %d\n", found);
    }
    else {
        printf ("Element not found int the given array\n");
    }
        
    return 0;
}

int lSearch(int arr[], int keyword)
{
    int i;
    for (i = 0; i < N; i++){
        if (arr[i] == keyword) // comparison
            return i;
    }
    return -1;
}
