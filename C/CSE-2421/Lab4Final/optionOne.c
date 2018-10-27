/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** optionOne.c created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

void optionOne(struct Table * table) {
    char *prompt;
    int studentId;
    
    // gets user input
    prompt = "Input the ID number of the student whose grades you'd like to see:";
    studentId = getIntFromUser(prompt);
    printf("\n");
    
    // prints info
    printHeaderInfo(table);
    printByIdNumber(table, studentId);
}
