/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** optionFour.c created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

void optionFour(struct Table * table) {
    char *prompt;
    int studentId;
    struct StudentEntry *studentEntryPtr;
    int index;
    
    // gets requested id
    prompt = "Input the ID number of the student whose grades you'd like to recalculate:";
    studentId = getIntFromUser(prompt);
    printf("\n");
    
    // gets student calculates final grades
    for(index = 0; index < table->students->size; index++) {
        studentEntryPtr = getStudentEntry(table->students, index);
        if (studentEntryPtr->studentId == studentId) {
            calculateFinalGrade(studentEntryPtr);
        }
    }
    
    // prints
    printHeaderInfo(table);
    printByIdNumber(table, studentId);
}
