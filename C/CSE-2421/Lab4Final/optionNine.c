/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** optionNine.c created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

void optionNine(struct Table * table) {
    int index, indexOfStudentToRemove;
    struct StudentEntry *removedStudent, *currentStudent;
    char *prompt;
    int studentId;
    
    prompt = "Input the ID number of the student who you'd like to remove:";
    indexOfStudentToRemove = -1;
    
    // gets input
    studentId = getIntFromUser(prompt);
    printf("\n");
    
    // gets index of studnet to remove
    for(index = 0; index < table->students->size; index++) {
        currentStudent = getStudentEntry(table->students, index);
        if(currentStudent->studentId == studentId) {
            indexOfStudentToRemove = index;
        }
    }
    
    // removes and deletes tudent
    removedStudent = removeStudentEntryFromTable(table, indexOfStudentToRemove);
    deleteStudentEntryPtr(removedStudent);
}
