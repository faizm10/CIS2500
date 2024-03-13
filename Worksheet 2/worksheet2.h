#define MAX_LEN_NAME 20
#define MAX_GRAD_STUDENTS 3

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct justTag {
    
    char name [MAX_LEN_NAME];
    char supervisor [MAX_LEN_NAME];
    int numCoursesDone;
    float currentPercentage;
} gradStudent;

void printGrad (gradStudent);

int read1Grads (FILE *file, gradStudent g [MAX_GRAD_STUDENTS]);

int read2Grads (FILE *file, gradStudent g [MAX_GRAD_STUDENTS]);

// write the prototype for oneMoreDone here

int read2Grads (FILE *file, gradStudent gsArray [MAX_GRAD_STUDENTS]{
file = fopen ("file2.txt", "r");
char fnG [MAX_LEN_NAME]; 
char InG [MAX_LEN_NAME]; 
char fnS [MAX_LEN_NAME]; 
char InS [MAX_LEN_NAME];
int id;
float currentP;
int count = 0;
char full [100]; //For the gets, max of 100 characters (the full line)
if (file == NULL) {
    printf("Error reading file");
    return -1;
}
while (fgets (full, 100, file){
//sscan scans from a string 
sscanf(full, "%s%s%s%s%d%f", fnG, InG, fnS, InS,
&id, &currentP);
//^^^strtok function can also be used
gsArray[count].numCoursesDone = id;
gArray[count].currentPercentage = currentP;
I/Doing what we mentioned on lines 21-22, for the name part of the struct
strat(fnG, " ");
strcat(fnG, InG);
strepy (gsArray [count].name,fnG);
//Repeating this same process for Supervisor
strat(fnS, " ");
strcat(fnS, InS);
stropy (gArray [count].supervisor,fnS);
/* If we want to do an gets instead of an fscanf
fgets (sArray[count].name, MAX_LEN_NAME, file);
However, this name will have an additional In new line at the end when it gets outputted So to get rid of it:
gsArray[count].name[strlen(gsArray[count].name
-1)] = 10';
*/
count++;
}

return count;
}
