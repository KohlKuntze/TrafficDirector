/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** addStudentEntry.c created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

void addStudentEntry(struct StudentEntry * newStudent, struct StudentEntryList * currentStudentEntryList) {
    struct StudentEntry* currentStudent;
    
    // Add where needed
    if(currentStudentEntryList->size == 0) {
        currentStudentEntryList->headStudent = newStudent;
    } else {
        currentStudent = currentStudentEntryList->headStudent;
        while(currentStudent->nextStudent != NULL) currentStudent = currentStudent->nextStudent;
        
        currentStudent->nextStudent = newStudent;
    }
    
    // Increment
    currentStudentEntryList->size = currentStudentEntryList->size + 1;
}
