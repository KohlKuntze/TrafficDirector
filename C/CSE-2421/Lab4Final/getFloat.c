/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** getFloat.c created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

float getFloat(struct FloatList * desiredList, int index) {
    struct FloatList floatList;
    struct FloatNode *current;
    int counter;
    float data;
    
    floatList = *desiredList;
    current = floatList.head;
    counter = 0;
    
    // sequence
    while(index > counter++) current = (*current).nextNode;
    data = (*current).data;
    
    // return data
    return data;
}
