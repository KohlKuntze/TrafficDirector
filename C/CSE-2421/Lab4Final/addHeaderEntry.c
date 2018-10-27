/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** addHeaderEntry.c created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

void addHeaderEntry(struct HeaderEntry * newHeader, struct HeaderEntryList * list) {
    struct HeaderEntry *currentHeader;
    
    // Add to list
    if(list->size == 0) {
        list->firstHeader = newHeader;
    } else {
        currentHeader = list->firstHeader;
        while(currentHeader->nextHeader != NULL) currentHeader = currentHeader->nextHeader;
        
        currentHeader->nextHeader = newHeader;
    }
    
    // increment
    list->size = list->size + 1;
}
