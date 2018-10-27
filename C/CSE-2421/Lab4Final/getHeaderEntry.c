/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** getHeaderEntry.c created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

struct HeaderEntry * getHeaderEntry(struct HeaderEntryList * list, int index) {
    struct HeaderEntry *headerEntryPtr;
    int counter;
    
    headerEntryPtr = list->firstHeader;
    counter = 0;
    
    // sequence
    while(index > counter++) headerEntryPtr = headerEntryPtr->nextHeader;
    
    // return pointer
    return headerEntryPtr;
}
