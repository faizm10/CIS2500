#include <stdio.h>
int countNumDig (int n);
int countNumStr(char *  str);

int main(){
    return 0;
}

int countNumDig (int n){
    if (n == 0){
        return 0;
    }
    else{
        printf("%d\n", n % 10);
        return 1 + countNumDig (n/10);
    }
}
int countNumStr(char *  str){
    if (strlen(str) == 0){
        return 0;
    }
    else if(isDigit (* str)){
        return 1+ countNumStr(str + 1);
    }
}