/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** makeStudentListPtr.c created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

struct StudentEntryList* makeStudentEntryListPtr() {
    struct StudentEntryList* studentEntryList;
    // allocate space and initialize
    studentEntryList = (struct StudentEntryList *) malloc(sizeof(struct StudentEntryList));
    studentEntryList->size = 0;
    studentEntryList->headStudent = NULL;
    // return pointer
    return studentEntryList;
}
