/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** optionTwo.c created by Kohl Kuntze
 
 */


#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

void optionTwo(struct Table * table) {
    char *prompt;
    char studentLastName[40];
    
    prompt = "Input the last name of the student whose grades you'd like to see:";
    
    // gets last name input
    getStringFromUser(prompt, studentLastName);
    printf("\n");
    
    // prints info
    printHeaderInfo(table);
    printByLastName(table, studentLastName);
}
