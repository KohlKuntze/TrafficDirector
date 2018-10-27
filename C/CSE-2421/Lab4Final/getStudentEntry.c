/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** getStudentUser.c created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

struct StudentEntry * getStudentEntry(struct StudentEntryList * currentStudentEntryList, int index) {
    struct StudentEntry *returnStudentPtr = currentStudentEntryList->headStudent;
    int counter = 0;
    
    // sequence
    while(index > counter++) returnStudentPtr = returnStudentPtr->nextStudent;
    
    // return pointer
    return returnStudentPtr;
}
