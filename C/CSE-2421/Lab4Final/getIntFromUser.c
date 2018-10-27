/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** getIntFromUser.c created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

int getIntFromUser(char *prompt) {
    int returnInt, counter;
    char charStr[40];
    char currentChar;
    int currentValue;
    int nonDigitFound;
    
    nonDigitFound = 0;
    
    getStringFromUser(prompt, charStr);
    returnInt = 0;
    
    // read string to get int value
    for(counter = 0; counter < 40; counter++) {
        currentChar = charStr[counter];
        if(nonDigitFound != 1) {
            if(currentChar >= '0' && currentChar <= '9') {
                returnInt = returnInt * 10;
                currentValue = currentChar - '0';
                returnInt += currentValue;
            } else {
                nonDigitFound = 1;
            }
        }
    }
    
    // return int value
    return returnInt;
}
