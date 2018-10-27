/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** getStringFromUser.c created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab4.h"

void getStringFromUser(char *prompt, char *returnString) {
    int sizeToCheck, counter;
    sizeToCheck = 40;
    printf("%s\n", prompt);
    fgets(returnString, sizeToCheck, stdin);
    
    // clean string
    for(counter = 0; counter < sizeToCheck; counter++) {
        if(returnString[counter] == '\n') {
            returnString[counter] = '\0';
        }
    }
}
