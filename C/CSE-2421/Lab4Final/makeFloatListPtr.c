/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** makeFloatListPtr.c created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

struct FloatList* makeFloatListPtr() {
    struct FloatList *listPtr;
    // allocate space and initialize
    listPtr = (struct FloatList*) malloc(sizeof(struct FloatList));
    listPtr->size = 0;
    listPtr->head = NULL;
    // return pointer
    return listPtr;
}
