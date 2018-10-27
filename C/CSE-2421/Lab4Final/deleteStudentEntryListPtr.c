/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** deleteStudentEntryListPtr.c created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

void deleteStudentEntryListPtr(struct StudentEntryList * list) {
    struct StudentEntry *studentEntryPtr;
    // Delete list
    while(list->size > 0) {
        studentEntryPtr = removeStudentEntry(list, 0);
        deleteStudentEntryPtr(studentEntryPtr);
    }
    
    // free pointer
    free(list);
}
