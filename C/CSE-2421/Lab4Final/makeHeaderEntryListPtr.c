//
/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** makeHeaderEntryListPtr.c created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

struct HeaderEntryList* makeHeaderEntryListPtr() {
    struct HeaderEntryList *headerEntryList;
    // allocate space and initialize
    headerEntryList = (struct HeaderEntryList *) malloc(sizeof(struct HeaderEntryList));
    headerEntryList->size = 0;
    headerEntryList->firstHeader = NULL;
    // return pointer
    return headerEntryList;
}
