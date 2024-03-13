#include "worksheet2.h"

int read2Grads (FILE *file, gradStudent gsArray [MAX_GRAD_STUDENTS]){
    
    int count = 0;
   
       char fnG [MAX_LEN_NAME];
       char lnG [MAX_LEN_NAME];
       char fnS [MAX_LEN_NAME];
       char lnS [MAX_LEN_NAME];
    
           int id;
           float currentP;
        
           char full [100];

           // validate if the file exists - TO DO
           // if (file == NULL)

   while (!feof (file)) {    // while it is not the end-of-file
      
      fgets (full, 100, file);
      
      // splitting members
      
      sscanf (full, "%s%s%s%s%d%f", fnG, lnG, fnS, lnS, &id, &currentP);
      gsArray [count].numCoursesDone = id;
      gsArray [count].currentPercentage = currentP;
      
      strcat (fnG, " ");
      strcat (fnG, lnG);      // now, fnG has Harry followed by space followed Dang
      
      strcpy (gsArray [count].name, fnG);
      
      strcat (fnS, " ");
      strcat (fnS, lnS);
      
      strcpy (gsArray [count].supervisor, fnS);
      count++;
      
   }
   return count;
}

