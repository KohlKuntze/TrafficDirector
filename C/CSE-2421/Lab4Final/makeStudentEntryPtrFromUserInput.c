/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** makeStudentEntryPtrFromUserInput.c created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab4.h"

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
    char *baseGradeChangePrompt, *currentPrompt, *space, *one, *two, *three, *colon;
    
    baseGradeChangePrompt = "Input grade for ";

    currentPrompt = (char *) malloc(100 * sizeof(char *));
    space = (char *) malloc(2 * sizeof(char *));
    one = (char *) malloc(2 * sizeof(char *));
    two = (char *) malloc(2 * sizeof(char *));
    three = (char *) malloc(2 * sizeof(char *));
    colon = (char *) malloc(2 * sizeof(char *));
    
    *(space) = ' ';
    *(one) = '1';
    *(two) = '2';
    *(three) = '3';
    *(colon) = ':';
    *(space + 1) = '\0';
    *(one + 1) = '\0';
    *(two + 1) = '\0';
    *(three + 1) = '\0';
    *(colon + 1) = '\0';
    
    // get details from input
    newNamePrompt = "Input new student's name:";
    getStringFromUser(newNamePrompt, newStudentName);
    newIdPrompt = "Input new student's ID:";
    newStudentId = getIntFromUser(newIdPrompt);
    
    // make new student
    newStudentEntry = makeStudentEntryPtr(newStudentName, newStudentId);
    
    entriesPerHeader = 3;
    
    // Get grade info
    for(outerCounter = 0; outerCounter < headerEntryList->size; outerCounter++) {
        currentHeaderEntry = getHeaderEntry(headerEntryList, outerCounter);
        
        strcpy(gradeChangePrompt, baseGradeChangePrompt);
        strcat(gradeChangePrompt, getHeaderLabel(currentHeaderEntry));
        strcat(gradeChangePrompt, space);
        
        // get grades for given header
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
    
    free(space);
    free(one);
    free(two);
    free(three);
    free(colon);
    
    // return new student
    return newStudentEntry;
}

