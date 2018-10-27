//
//  AuxilaryFunctions.c
//  Lab4
//
//  Created by Kohl Kuntze on 10/2/18.
//  Copyright © 2018 Kohl Kuntze. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

void getStringFromUser(char *prompt, char *returnString) {
    int sizeToCheck, counter;
    sizeToCheck = 40;
    printf("%s\n", prompt);
    //scanf("%s[^\n]", returnString);
    fgets(returnString, sizeToCheck, stdin);
    
    for(counter = 0; counter < sizeToCheck; counter++) {
        if(returnString[counter] == '\n') {
            returnString[counter] = '\0';
        }
    }
}

int getIntFromUser(char *prompt) {
    int returnInt, counter;
    char charStr[40];
    char currentChar;
    int currentValue;
    int nonDigitFound;
    
    nonDigitFound = 0;
    
    getStringFromUser(prompt, charStr);
    returnInt = 0;
    
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
    
    return returnInt;
}

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
    
    for(counter = 0; counter < numAfterDecimal; counter++) {
        returnFloat = returnFloat / 10.0f;
    }
    
    if(isNegative == 1) {
        returnFloat = returnFloat * -1.0f;
    }
    
    return returnFloat;
}

struct StudentEntry * makeStudentEntryPtrFromUserInput(struct HeaderEntryList * headerEntryList) {
    char gradeChangePrompt[100];
    struct HeaderEntry *currentHeaderEntry;
    char *newNamePrompt;
    char newStudentName[40];
    char *newIdPrompt;
    int newStudentId;
    struct StudentEntry *newStudentEntry;
    float currentGrade;
    int outerCounter, innerCounter, entriesPerHeader;
    
    newNamePrompt = "Input new student's name:";
    getStringFromUser(newNamePrompt, newStudentName);
    newIdPrompt = "Input new student's ID:";
    newStudentId = getIntFromUser(newIdPrompt);
    
    newStudentEntry = makeStudentEntryPtr(newStudentName, newStudentId);
    
    entriesPerHeader = 3;
    char baseGradeChangePrompt[] = {'I', 'n', 'p', 'u', 't', ' ', 'd', 'e', 's', 'i', 'r', 'e', 'd', ' ', 'g', 'r', 'a', 'd', 'e', ' ', 'f', 'o', 'r', ' ', '\0'};
    char currentPrompt[100];
    char space[] = {' ', '\0'};
    char one[] = {'1', '\0'};
    char two[] = {'2', '\0'};
    char three[] = {'3', '\0'};
    char colon[] = {':', '\0'};
    
    
    for(outerCounter = 0; outerCounter < headerEntryList->size; outerCounter++) {
        currentHeaderEntry = getHeaderEntry(headerEntryList, outerCounter);
        
        strcpy(gradeChangePrompt, baseGradeChangePrompt);
        strcat(gradeChangePrompt, getHeaderLabel(currentHeaderEntry));
        strcat(gradeChangePrompt, space);
        for(innerCounter = 0; innerCounter < entriesPerHeader; innerCounter++) {
            strcpy(currentPrompt, gradeChangePrompt);
            switch(innerCounter) {
                case 0:
                    strcat(currentPrompt, one);
                    break;
                case 1:
                    strcat(currentPrompt, two);
                    break;
                default:
                    strcat(currentPrompt, three);
                    break;
            }
            
            strcat(currentPrompt, colon);
            currentGrade = getFloatFromUser(currentPrompt);
            changeGrade(newStudentEntry, currentGrade, (3 * outerCounter + innerCounter));
        }
    }
    
    return newStudentEntry;
}
