/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** makeTablePtr.c created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

struct Table* makeTablePtr() {
    struct Table *table;
    // Allocate space and initialize
    table = (struct Table *) malloc(sizeof(struct Table));
    table->students = makeStudentEntryListPtr();
    table->headerEntryList = makeHeaderEntryListPtr();
    
    // return pointer
    return table;
}
