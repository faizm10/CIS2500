#include "worksheet2.h"

int read1Grads (FILE *file, gradStudent gsArray [MAX_GRAD_STUDENTS]) {
    
    int i = 0;
    char fname [MAX_LEN_NAME], lname [MAX_LEN_NAME];
    
    char sFname [MAX_LEN_NAME], sLname [MAX_LEN_NAME];
    
    while (!feof(file)) {
        
        fscanf (file, "%s%s%s%s%d%f", fname, lname, sFname, sLname, &gsArray [i].numCoursesDone, &gsArray [i].currentPercentage);
        
        strcpy (gsArray [i].name, fname);
        strcat (gsArray [i].name, " ");
        strcat (gsArray [i].name, lname);
        
        strcpy (gsArray [i].supervisor, sFname);
        strcat (gsArray [i].supervisor, " ");
        strcat (gsArray [i].supervisor, sLname);
        
        i++;
    }

    return i;
}



