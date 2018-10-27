/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** optionSix.c created by Kohl Kuntze
 
 */


#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

// gets category
int getCategory(struct Table * table) {
    int option;
    char *prompt;
    prompt = "Input desired category:";
    
    printf("Select a category:\n");
    printf("1) %s\n", getHeaderLabel(getHeaderEntry(table->headerEntryList, 0)));
    printf("2) %s\n", getHeaderLabel(getHeaderEntry(table->headerEntryList, 1)));
    printf("3) %s\n", getHeaderLabel(getHeaderEntry(table->headerEntryList, 2)));
    printf("4) %s\n", getHeaderLabel(getHeaderEntry(table->headerEntryList, 3)));
    
    option = getIntFromUser(prompt);
    return --option;
}

// gets subscore index
int getSubScoreIndex() {
    int option;
    char *prompt;
    prompt = "Which subscore would you like to change (1-3):";
    option = getIntFromUser(prompt);
    return --option;
}

// gets new grade
float getNewGrade() {
    int newGrade;
    char *prompt;
    prompt = "Please input the new grade:";
    newGrade = getFloatFromUser(prompt);
    return newGrade;
}

void optionSix(struct Table * table) {
    int index, category, scoreIndex;
    char *prompt;
    int studentId;
    float newGrade;
    struct StudentEntry *studentEntryPtr;
    
    // gets user input
    prompt = "Input the ID number of the student whose grades you'd like to edit:";
    studentId = getIntFromUser(prompt);
    
    category = getCategory(table);
    scoreIndex = getSubScoreIndex();
    newGrade = getNewGrade();
    
    
    // changes grade
    for(index = 0; index < table->students->size; index++) {
        studentEntryPtr = getStudentEntry(table->students, index);
        if (studentEntryPtr->studentId == studentId) {
            changeGrade(studentEntryPtr, newGrade, 3 * category + scoreIndex);
        }
    }
}
