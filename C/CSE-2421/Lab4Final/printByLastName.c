/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** printByLastName.c created by Kohl Kuntze
 
 */


#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

void printByLastName(struct Table * table, char *lastName) {
    int index;
    struct StudentEntry *studentEntryPtr;
    char *currentLastName;
    
    for(index = 0; index < table->students->size; index++) {
        studentEntryPtr = getStudentEntry(table->students, index);
        currentLastName = studentEntryPtr->studentName;
        // finds and prints by last name substring
        if(strstr(currentLastName, lastName) != NULL) {
            printGrades(studentEntryPtr);
        }
    }
}
