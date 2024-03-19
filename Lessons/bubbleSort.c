
#include <stdio.h>
/*bubble sort */

#define SIZE 8

void bubbleSort (int array [SIZE]);
void printArray (int array [SIZE]);

int main()
{
    int array[] = {20, 4, 5, 90, -8, 6, 17, 39};
   // Best case: {1,2,3,4,5,6,7,8,9,10};
   
    printf ("Before Sorting using bubble sort:\n");
    printArray (array);
    
    printf("\n");
    
    bubbleSort (array);
    
    printf("\n");
    printf ("After Sorting using bubble sort:\n");
    printArray (array);
    
    return 0;
    
}

/* sorts an array of integers in ascending order */

void bubbleSort (int array [SIZE]) {
    
    int i, j;
    int temp;
    int flag = 0;
    int countInner = 0;
    
    for (i = 0 ; !flag && i < SIZE - 1; i++)    // pass
    {
       countInner = 0;
        for (j = 0 ;  j < SIZE - i - 1; j++)
        {
            if (array[j] > array[j+1])
            {
                temp       = array[j];
                array[j]   = array[j+1];
                array[j+1] = temp;
                countInner++;
            }
        }
       if (countInner == 0) {
          flag = 1;
       }
    }
}

void printArray (int array [SIZE]) {
    
    int i;
   
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
}
