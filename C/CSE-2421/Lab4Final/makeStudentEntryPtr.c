/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** makeStudentEntryPtr.c created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab4.h"

struct StudentEntry* makeStudentEntryPtr(char * name, int studentIdentificationNum) {
    struct StudentEntry* student;
    char *namePtr;
    int counter;
    // allocate space and initialize
    namePtr = (char *) malloc(40 * sizeof(char *));
    student = (struct StudentEntry *) malloc(sizeof(struct StudentEntry));
    strcpy(namePtr, name);
    
    student->studentName = namePtr;
    
    student->grades = makeFloatListPtr();
    
    // set all grades to -1.0
    for(counter = 0; counter < 12; counter++) {
        addFloat(student->grades, -1.00);
    }
    
    student->studentId = studentIdentificationNum;
    student->nextStudent = NULL;
    student->finalGrade = -1.00f;
    
    // return pointer
    return student;
}
