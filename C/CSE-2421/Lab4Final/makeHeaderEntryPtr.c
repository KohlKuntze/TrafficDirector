/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** makeHeaderEntryPtr.c created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab4.h"

struct HeaderEntry* makeHeaderEntryPtr(char * headerLabel) {
    struct HeaderEntry* headerEntry;
    char *labelPtr;
    // allocate space and initialize
    headerEntry = (struct HeaderEntry *) malloc(sizeof(struct HeaderEntry));
    labelPtr = (char *) malloc(sizeof(char *));
    strcpy(labelPtr, headerLabel);
    
    headerEntry->headerLabel = labelPtr;
    headerEntry->nextHeader = NULL;
    
    // return pointer
    return headerEntry;
}
