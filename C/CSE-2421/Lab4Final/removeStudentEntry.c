/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** removeStudentEntry.c created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

struct StudentEntry * removeStudentEntry(struct StudentEntryList * currentStudentEntryList, int index) {
    struct StudentEntry *returnStudentPtr;
    int counter;
    struct StudentEntry *temp;
    returnStudentPtr = NULL;
    
    if(index < currentStudentEntryList->size) {
        
        // decides which to find
        if (currentStudentEntryList->size == 1 || index == 0) {
            returnStudentPtr = currentStudentEntryList->headStudent;
            currentStudentEntryList->headStudent = currentStudentEntryList->headStudent->nextStudent;
        } else {
            temp = currentStudentEntryList->headStudent;
            counter = 0;
            
            // sequence
            while((index - 1) > counter++) temp = temp->nextStudent;
            
            returnStudentPtr = temp->nextStudent;
            temp->nextStudent = temp->nextStudent->nextStudent;
        }
        
        // decremnt
        currentStudentEntryList->size = currentStudentEntryList->size - 1;
    }
    
    // return pointer
    return returnStudentPtr;
}
