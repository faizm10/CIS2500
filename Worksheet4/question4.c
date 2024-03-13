#include <stdio.h>
#include <stdlib.h>

int *ptr = NULL;
int i = 0;
char ans = 'y';

int main()
{
    while (ans == 'y'){
        if (ptr == NULL){
            ptr = malloc(sizeof(int) * 1);
            ptr[0] = (i - 1) * 2;
        }
        else{
            ptr = realloc(ptr, sizeof(int) * (i + 1));
            ptr[i] = (i - 1) * 2;
        }
        i++;
        printf("Continue?: ");
        scanf("%c", &ans);
        getchar();
    }
    for (int j = 0; j < i; i++){
        printf("%d\n", ptr[j]);
    }
    // free the dynamic space allocated
    free(ptr);
}