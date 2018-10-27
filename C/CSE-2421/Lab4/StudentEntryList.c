/*
 StudentEntryList.c
 Lab4
 
 Created by Kohl Kuntze on 9/28/18.
 Copyright © 2018 Kohl Kuntze. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"


struct StudentEntryList makeStudentEntryListObj() {
    struct StudentEntry* head;
    head = (struct StudentEntry*) malloc(sizeof(struct StudentEntry));
    head->nextStudent = NULL;
    
    struct StudentEntryList returnList = {0, head};
    
    return returnList;
}

struct StudentEntryList* makeStudentEntryListPtr() {
    struct StudentEntryList* studentEntryList;
    studentEntryList = (struct StudentEntryList *) malloc(sizeof(struct StudentEntryList));
    studentEntryList->size = 0;
    studentEntryList->headStudent = NULL;
    
    return studentEntryList;
}

void addStudentEntry(struct StudentEntry * newStudent, struct StudentEntryList * currentStudentEntryList) {
    struct StudentEntry* currentStudent;
    
    if(currentStudentEntryList->size == 0) {
        currentStudentEntryList->headStudent = newStudent;
    } else {
        currentStudent = currentStudentEntryList->headStudent;
        while(currentStudent->nextStudent != NULL) currentStudent = currentStudent->nextStudent;
        
        currentStudent->nextStudent = newStudent;
    }
    
    currentStudentEntryList->size = currentStudentEntryList->size + 1;
}

struct StudentEntry * getStudentEntry(struct StudentEntryList * currentStudentEntryList, int index) {
    struct StudentEntry *returnStudentPtr = currentStudentEntryList->headStudent;
    int counter = 0;
    
    while(index > counter++) returnStudentPtr = returnStudentPtr->nextStudent;
    
    return returnStudentPtr;
}

struct StudentEntry * removeStudentEntry(struct StudentEntryList * currentStudentEntryList, int index) {
    struct StudentEntry *returnStudentPtr;
    int counter;
    struct StudentEntry *temp;
    returnStudentPtr = NULL;
    
    if(index < currentStudentEntryList->size) {
        if (currentStudentEntryList->size == 1 || index == 0) {
            returnStudentPtr = currentStudentEntryList->headStudent;
            currentStudentEntryList->headStudent = currentStudentEntryList->headStudent->nextStudent;
        } else {
            temp = currentStudentEntryList->headStudent;
            counter = 0;
            
            while((index - 1) > counter++) temp = temp->nextStudent;
            
            returnStudentPtr = temp->nextStudent;
            temp->nextStudent = temp->nextStudent->nextStudent;
        }
        currentStudentEntryList->size = currentStudentEntryList->size - 1;
    }
    
    return returnStudentPtr;
}

void deleteStudentEntryListPtr(struct StudentEntryList * list) {
    struct StudentEntry *studentEntryPtr;
    
    while(list->size > 0) {
        studentEntryPtr = removeStudentEntry(list, 0);
        deleteStudentEntryPtr(studentEntryPtr);
    }
    
    free(list);
}
