/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** getFloatFromUser.c created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

float getFloatFromUser(char *prompt) {
    float returnFloat;
    int counter, numAfterDecimal;
    char charStr[40];
    char currentChar;
    int currentValue;
    int nonDigitFound, decimalFound, isNegative, checkValue;
    
    nonDigitFound = 0;
    numAfterDecimal = 0;
    isNegative = 0;
    decimalFound = 0;
    getStringFromUser(prompt, charStr);
    
    returnFloat = 0.0f;
    
    // read string for float related characters
    for(counter = 0; counter < 40; counter++) {
        currentChar = *(charStr + counter);
        checkValue = 0;
        if((currentChar >= '0' && currentChar <= '9') || currentChar == '.' || currentChar == '-') {
            checkValue = 1;
        }
        
        if(nonDigitFound == 0) {
            if(checkValue == 1) {
                if(currentChar >= '0' && currentChar <= '9') {
                    returnFloat = returnFloat * 10.0f;
                    currentValue = currentChar - '0';
                    returnFloat += currentValue;
                    
                    if (decimalFound == 1) {
                        numAfterDecimal++;
                    }
                } if(currentChar == '.'){
                    decimalFound = 1;
                } else if(currentChar == '-') {
                    isNegative = 1;
                }
            } else {
                nonDigitFound = 1;
            }
        }
    }
    
    // correct number of decimal places
    for(counter = 0; counter < numAfterDecimal; counter++) {
        returnFloat = returnFloat / 10.0f;
    }
    
    // if negative multiply by negative one
    if(isNegative == 1) {
        returnFloat = returnFloat * -1.0f;
    }
    
    return returnFloat;
}
