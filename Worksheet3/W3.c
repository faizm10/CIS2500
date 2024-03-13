#include <stdio.h>
#include <string.h>
#define MAX_CHARS 20000

void firstChars(char filename[], int howMany);
void lastChars(char filename[], int howMany);

int main(){
    lastChars("courses.txt", 100);
}
void firstChars(char filename[], int howMany){
    FILE *fp;
    char buffer [MAX_CHARS];
    int charsRead;

    fp = open(filename, "r");
    charsRead=fread(buffer, sizeof(char), howMany, fp);
    for (int i =0;i<charsRead;i++){
        printf("%c ", buffer [i]);
    }
}

void lastChars(char filename[], int howMany){
    FILE *fp = fopen (filename, "rb");
    char buffer [MAX_CHARS];
    int charsRead;
    int fileSize;

    fseek(fp,-howMany*sizeof(char), SEEK_END);
    charsRead=fread(buffer, sizeof(char), howMany, fp);

    for (int i =0;i<charsRead;i++){
        printf("%c ", buffer [i]);
    }

}
