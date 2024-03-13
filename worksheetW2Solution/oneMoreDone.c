#include "worksheet2.h"

void oneMoreDone (gradStudent * g) {

   float marks, newAv;
   
   printf ("Enter marks for the new course: ");
   scanf ("%f", &marks);
   
   newAv = (marks + g->currentPercentage * g->numCoursesDone) / (g->numCoursesDone + 1);
   g->currentPercentage = newAv;
   g->numCoursesDone++;

}

