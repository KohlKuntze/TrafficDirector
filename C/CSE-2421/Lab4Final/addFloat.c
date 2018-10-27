/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** addFloat.c Created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

void addFloat(struct FloatList * desiredList, float addedFloat) {
    // Make variables
    struct FloatNode* newNode;
    struct FloatNode* current;
    int counter;
    
    // Allocate space
    newNode = (struct FloatNode*) malloc(sizeof(struct FloatNode));
    newNode->data = addedFloat;
    
    // Add to list
    if(desiredList->size == 0) {
        desiredList->head = newNode;
        desiredList->head->nextNode = NULL;
    } else {
        current = desiredList->head;
        counter = 0;
        
        while((desiredList->size - 1) > counter++) current = current->nextNode;
        
        current->nextNode = newNode;
        current->nextNode->nextNode = NULL;
    }
    
    // Sequence
    desiredList->size = desiredList->size + 1;
}
