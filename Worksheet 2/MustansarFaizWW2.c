//Q1a:

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

//Q1b:

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
      strcat (fnG, lnG);     
      
      strcpy (gsArray [count].name, fnG);
      
      strcat (fnS, " ");
      strcat (fnS, lnS);
      
      strcpy (gsArray [count].supervisor, fnS);
      count++;
      
   }
   return count;
}

//Q1c:

#include "worksheet2.h"

void oneMoreDone (gradStudent * g) {

   float marks, newAv;
   
   printf ("Enter marks for the new course: ");
   scanf ("%f", &marks);
   
   newAv = (marks + g->currentPercentage * g->numCoursesDone) / (g->numCoursesDone + 1);
   g->currentPercentage = newAv;
   g->numCoursesDone++;

}


//Q2

// worksheetW2: read1Grads.o read2Grads.o w2Main.o oneMoreDone.o
// 	gcc -Wall -std=c99 read1Grads.o oneMoreDone.o read2Grads.o w2Main.o -o worksheetW2

// read2Grads.o: read2Grads.c
// 	gcc -Wall -std=c99 -c read2Grads.c

// read1Grads.o: read1Grads.c
// 	gcc -Wall -std=c99 -c read1Grads.c

// oneMoreDone.o: oneMoreDone.c
// 	gcc -Wall -std=c99 -c oneMoreDone.c

// w2Main.o: w2Main.c
// 	gcc -Wall -std=c99 -c w2Main.c
	
// clean:
// 	rm *.o worksheetW2


