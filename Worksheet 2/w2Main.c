#include "worksheet2.h"

int main () {

    int numRead;
    gradStudent g [MAX_GRAD_STUDENTS];
    
    FILE * fptr = fopen ("file1.txt", "r");

    numRead = read1Grads (fptr, g);
    
    for (int i = 0; i < numRead; i++) {
        printGrad (g[i]);
    
    }
    
    fclose (fptr);
   
   /*
    
    printf ("***************Done file 1 ***************\n");
            
    fptr = fopen ("file2.txt", "r");
    
    numRead = read2Grads (fptr, g);
    
    for (int i = 0; i < numRead; i++) {
        printGrad (g[i]);
        
    }
    
    printf ("***************Done file 2 ***************\n");
   */
   /*
     call oneMoreDone for Harry Dang here - note that he is the first grad in g
   */
   
    return 0;
}

void printGrad (gradStudent g) {

   printf ("Name: %s\n", g.name);
   printf ("Supervisor: %s\n", g.supervisor);
   printf ("Number of Courses Done so far: %d\n", g.numCoursesDone);
   printf ("Current percentage: %.2f\n", g.currentPercentage);

}

int read1Grads (FILE *file, gradStudent g [MAX_GRAD_STUDENTS]){
    char fnG [MAX_LEN_NAME];
    char lnG [MAX_LEN_NAME];
    char fnS [MAX_LEN_NAME];
    char lnS [MAX_LEN_NAME];
    int id;
    float currentP;
    int count = 0;

    //valudate if the file exists - TO DO
    // if (file==NULL){
    //     printf("Doesnt Exist");
    //     return -1;
    // }

    while (!feof(file)){ // while it is not the end of the file
        fscanf(file, "%s%s%s%s%d%f", fnG, lnG, fnS, lnS, &id, &currentP);

        g[count].numCoursesDone.id;
        g[count].currentPercentage = currentP;

        strcat(fnG, " ");
        strcat(fnG, lnG);

        strcpy (g [count].name, fnG);

        strcat(fnS, " ");
        strcat(fnS, lnS);
        strcpy (g [count].supervisor,fnS);

        count ++;
    }
    //or if we want to use fgets
    char ch;
    while (!feof(file)){

        fgets(g[count].name, MAX_LEN_NAME, file);
        g[count].name[strlen(g[count].name - 1)] = 10;
        fgets(gsArray[count].supervisor, MAX_LEN_NAME, file);
        fscanf("file", "%d%f", &g[count].numCoursesDone, &g[count].currentPercentage);
        fscanf(file, "%c",&ch);
        count++;
    }
    
}


