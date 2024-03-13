#include <stdio.h>

struct Student {
   char firstName [30] ;
   char surname [30];
   int studentID ;
   float labMarks [10];
};
typedef struct Student Students1300; // students1300 is NOT a variable

float averageLabMarks (Students1300 stu);

//reads values from the keyboard and stores them in aStudent
Students1300 setStudentInfoV1 (void);

int main() {
   
   float result;
   Students1300 aStudent;   //variable of type Students1300 OR struct Student
   
   aStudent = setStudentInfoV1 ();
   
   printf ("Firstname = %s\n", aStudent.firstName);
   result = averageLabMarks (aStudent);
   
   printf ("Avg = %.2f\n", result);
   
   setStudentInfoV2 (&aStudent);
   
   return 0;
}

void setStudentInfoV2 (StudentRecord * studData) {

    scanf ("%s", stuData->firstName); // (*stuData).firstName
    scanf ("%s", stuData->surName);
    scanf ("%d", &stuData->studentId);

    for (int i = 0; i < 3; i++) {
        scanf ("%f", &stuData->labMarks [i]);
    }
}

Students1300 setStudentInfoV1 (void) {
   
   Students1300 stu;
   
   scanf ("%s", stu.firstName);
   scanf ("%s", stu.surname);
   
   scanf ("%d", &stu.studentID);
   
   for (int i = 0; i < 10; i++) {
      scanf ("%f", &stu.labMarks [i]);
   }
   
   return stu;
}

float averageLabMarks (Students1300 stu) {
   
   float sum = 0;
   
   for (int i = 0; i < 10; i++) {
      
      sum = sum + stu.labMarks[i];
   }
   return sum / 10;
}




// 5. Declare an array of 10 elements where each
// element is of type StudentRecord – name the array lotsOfStudents.

//Students1300 lotsOfStudents [100];

//Assign the following values to the last element of lotsOfStudents:


/*
for (j = 0; j < 100; j++) {
   
   strcpy (lotsOfStudents [j].firstName, "Ritu");
   
   scanf ("%s", lotsOfStudents [j].surname);
   
   scanf ("%d", & lotsOfStudents[j].studentID);
   
   for (i = 0; i < 10; i++) {
      
      scanf ("%f", &lotsOfStudents[j].labMarks[i]);
   }
   
}

*/


