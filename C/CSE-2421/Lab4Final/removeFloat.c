/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** removeFloat.c created by Kohl Kuntze
 
 */


#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

float removeFloat(struct FloatList * desiredList, int index) {
    int counter;
    struct FloatNode *removedNode, *temp;
    float tempValue;
    
    if(index <= desiredList->size && index >=0) {
        temp = desiredList->head;
        
        // finds correct float to remove
        if(index == 0) {
            desiredList->head = desiredList->head->nextNode;
            tempValue = temp->data;
            free(temp);
        }else{
            counter = 0;
            
            // sequence
            while((index - 1) > counter++) temp = temp->nextNode;
            
            tempValue = temp->nextNode->data;
            removedNode = temp->nextNode;
            temp->nextNode = temp->nextNode->nextNode;
            free(removedNode);
        }
        
        // decrement
        desiredList->size = desiredList->size - 1;
        
        // return pointer
        return tempValue;
    } else {
        
        // default value
        return 0;
    }
}
