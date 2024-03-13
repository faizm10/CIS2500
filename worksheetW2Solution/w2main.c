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
    
    printf ("***************Done file 1 ***************\n");
            
    fptr = fopen ("file2.txt", "r");
    
    numRead = read2Grads (fptr, g);
    
    for (int i = 0; i < numRead; i++) {
        printGrad (g[i]);
        
    }
    
    printf ("***************Done file 2 ***************\n");
   
    // call oneMoreDone for Harry Dang here - note that he is the first grad in g
   
   
    printGrad (g[0]);      // print Harry Dang's updated info
   
    return 0;
}

void printGrad (gradStudent g) {

   printf ("Name: %s\n", g.name);
   printf ("Supervisor: %s\n", g.supervisor);
   printf ("Number of Courses Done so far: %d\n", g.numCoursesDone);
   printf ("Current percentage: %.2f\n", g.currentPercentage);

}
