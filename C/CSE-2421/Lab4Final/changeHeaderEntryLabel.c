/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** changeHeaderEntryLabel.c created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab4.h"

void changeHeaderEntryLabel(struct HeaderEntry * headerEntry, char * newHeaderName) {
    free(headerEntry->headerLabel);
    
    char *labelPtr;
    labelPtr = (char *) malloc(sizeof(char *));
    
    // Copy new header
    strcpy(labelPtr, newHeaderName);
    
    // Assign
    headerEntry->headerLabel = labelPtr;
}
