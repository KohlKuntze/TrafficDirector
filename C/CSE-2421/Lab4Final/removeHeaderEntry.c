/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** removeHeaderEntry.c created by Kohl Kuntze
 
 */


#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

struct HeaderEntry * removeHeaderEntry(struct HeaderEntryList * list, int index) {
    struct HeaderEntry *returnHeaderPtr;
    int counter;
    struct HeaderEntry *temp;
    
    returnHeaderPtr = NULL;
    
    if(index < list->size) {
        
        // determinews which to remove
        if (list->size == 1 || index == 0) {
            returnHeaderPtr = list->firstHeader;
            list->firstHeader = list->firstHeader->nextHeader;
        } else {
            temp = list->firstHeader;
            counter = 0;
            
            // sequence
            while((index - 1) > counter++) temp = temp->nextHeader;
            
            returnHeaderPtr = temp->nextHeader;
            temp->nextHeader = temp->nextHeader->nextHeader;
        }
        
        // decrement
        list->size = list->size - 1;
    }
    
    // return pointer
    return returnHeaderPtr;
}
