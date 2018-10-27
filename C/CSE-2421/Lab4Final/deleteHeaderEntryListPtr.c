/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** deleteHeaderEntryListPtr.c created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

void deleteHeaderEntryListPtr(struct HeaderEntryList * list) {
    struct HeaderEntry *headerEntryPtr;
    
    // Delete list
    while(list->size > 0) {
        headerEntryPtr = removeHeaderEntry(list, 0);
        deleteHeaderEntryPtr(headerEntryPtr);
    }
    
    // free pointer
    free(list);
}
