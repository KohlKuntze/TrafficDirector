/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** changeFloat.c created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

void changeFloat(struct FloatList * desiredList, float newFloat, int index) {
    struct FloatNode* current;
    int counter;
    
    current = desiredList->head;
    counter = 0;
    
    // Find value
    while(index > counter++) current = current->nextNode;
    
    // change value
    current->data = newFloat;
}
