/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** optionSeven.c created by Kohl Kuntze
 
 */


#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

void optionSeven(struct Table * table) {
    struct StudentEntry *studentEntryPtr;
    int index;
    printHeaderInfo(table);
    
    // calculates and prints students
    for(index = 0; index < table->students->size; index++) {
        studentEntryPtr = getStudentEntry(table->students, index);
        calculateFinalGrade(studentEntryPtr);
        printByIdNumber(table, studentEntryPtr->studentId);
    }
}
