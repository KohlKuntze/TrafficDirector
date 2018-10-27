//
//  test.c
//  Lab4
//
//  Created by Kohl Kuntze on 9/30/18.
//  Copyright © 2018 Kohl Kuntze. All rights reserved.
//

#include "array.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int runFloatArrayPointerTests() {
    struct FloatList *currentList = makeFloatListPtr();
    int i, returnValue = 0;
    
    for(i = 0; i < 5; i++) {
        addFloat(currentList, (float) i);
    }
    
    changeFloat(currentList, 10.00, 1);
    if(getFloat(currentList, 1) == 10.00) {
        changeFloat(currentList, 1.00, 1);
    }
    
    for(i = 0; i < 5; i++) {
        float currentFloat = getFloat(currentList, i);
        
        if(currentFloat != (float) i) {
            printf("ERROR: runFloatArrayTests (get), expected: %.2f, but got %.2f\n", (float) i, currentFloat);
            returnValue++;
        }
    }
    
    for(i = 0; i < 5; i++) {
        float floatVal = getFloat(currentList, (4 - i));
        float currentFloat = removeFloat(currentList, (4 - i));
        
        if(currentFloat - floatVal != 0) {
            printf("ERROR: runFloatArrayTests (remove), expected: %.2f, but got %.2f\n", (float) (4 - i), currentFloat);
            returnValue++;
        }
    }
    
    deleteFloatListPtr(currentList);
    
    return returnValue;
}

int stringChecker(char actual[],char expected[]){
    int i,result=1;
    for(i=0; actual[i]!='\0' || expected[i]!='\0'; i++) {
        if(actual[i] != expected[i]) {
            result=0;
            break;
        }
    }
    return result;
}

int runStudentEntryTests() {
    int returnValue = 0;
    
    char studentName[] = {'K', 'o', 'h', 'l', ' ', 'K', 'u', 'n', 't', 'z', 'e', '\0'};
    int idNum = 726111;
    
    char otherStudentName[] = {'M', 'a', 'r', 'i', 'n', ' ', 'K', 'u', 'n', 't', 'z', 'e', '\0'};
    int otherIdNum = 735518;
    
    struct StudentEntry *kohlPtr, *marinPtr;
    kohlPtr = makeStudentEntryPtr(studentName, idNum);
    marinPtr = makeStudentEntryPtr(otherStudentName, otherIdNum);
    
    int index;
    for(index = 0; index < 12; index++) {
        changeGrade(kohlPtr, (float) (index * 8), index);
    }
    
    for(index = 0; index < 12; index++) {
        changeGrade(marinPtr, (float) (index * 7), index);
    }
    
    if(stringChecker(kohlPtr->studentName, studentName) != 1) {
        printf("ERROR: Student name not correct, actual: %s vs. %s\n", kohlPtr->studentName, studentName);
        returnValue++;
    }
    
    if(stringChecker(marinPtr->studentName, otherStudentName) != 1) {
        printf("ERROR: Other student name not correct, actual: %s vs. %s\n", marinPtr->studentName, otherStudentName);
        returnValue++;
    }
    
    if(idNum != kohlPtr->studentId) {
        printf("ERROR: Student ID not correct, actual: %i vs. %i\n", kohlPtr->studentId, idNum);
        returnValue++;
    }
    
    if(otherIdNum != marinPtr->studentId) {
        printf("ERROR: Other student ID not correct, actual: %i vs. %i\n", marinPtr->studentId, otherIdNum);
        returnValue++;
    }
    
    //printf("Should print Kohl (8):\n");
    //printGrades(kohlPtr);
    //printf("Should print Marin (7):\n");
    //printGrades(marinPtr);
    
    deleteStudentEntryPtr(kohlPtr);
    deleteStudentEntryPtr(marinPtr);

    return returnValue;
}

int runStudentEntryListTests() {
    int returnValue = 0;
    int index;
    
    char studentName[] = {'K', 'o', 'h', 'l', ' ', 'K', 'u', 'n', 't', 'z', 'e', '\0'};
    int idNum = 726111;
    
    char otherStudentName[] = {'M', 'a', 'r', 'i', 'n', ' ', 'K', 'u', 'n', 't', 'z', 'e', '\0'};
    int otherIdNum = 735518;
    
    struct StudentEntry *kohlPtr, *marinPtr, *holder;
    kohlPtr = makeStudentEntryPtr(studentName, idNum);
    marinPtr = makeStudentEntryPtr(otherStudentName, otherIdNum);
    
    struct StudentEntryList *studentEntryList = makeStudentEntryListPtr();
    
    if(studentEntryList->size != 0) {
        printf("ERROR: StudentEntryList not properly constructed");
        returnValue++;
    }
    
    addStudentEntry(kohlPtr, studentEntryList);
    
    if(studentEntryList->size != 1) {
        printf("ERROR: StudentEntryList not properly constructed");
        returnValue++;
    }
    
    holder = getStudentEntry(studentEntryList, 0);
    //printf("Should print Kohl:\n");
    //printGrades(holder);
    
    addStudentEntry(marinPtr, studentEntryList);
    
    if(studentEntryList->size != 2) {
        printf("ERROR: StudentEntryList did not add one correctly");
        returnValue++;
    }
    
    holder = getStudentEntry(studentEntryList, 0);
    //printf("Should print Kohl:\n");
    //printGrades(holder);
    for(index = 0; index < 12; index++) {
        changeGrade(holder, (float) (index * 8), index);
    }
    //printGrades(holder);
    
    holder = getStudentEntry(studentEntryList, 1);
    //printf("Should print Marin:\n");
    for(index = 0; index < 12; index++) {
        changeGrade(holder, (float) (index * 7), index);
    }
    //printGrades(holder);
    
    holder = removeStudentEntry(studentEntryList, 1);
    if(studentEntryList->size != 1) {
        printf("ERROR: StudentEntryList did not remove one correctly");
        returnValue++;
    }
    //printGrades(holder);
    deleteStudentEntryPtr(holder);
    
    deleteStudentEntryListPtr(studentEntryList);
    
    return returnValue;
}

int runHeaderEntryTests() {
    int returnValue = 0;
    
    char headerOne[] = {'O', 'n', 'e', '\0'};
    char headerTwo[] = {'T', 'w', 'o', '\0'};
    char headerThree[] = {'T', 'h', 'r', 'e', 'e', '\0'};
    char headerFour[] = {'F', 'o', 'u', 'r', '\0'};
    
    struct HeaderEntry *headerEntryOne;
    headerEntryOne = makeHeaderEntryPtr(headerOne);
    
    struct HeaderEntry *headerEntryTwo;
    headerEntryTwo = makeHeaderEntryPtr(headerTwo);
    
    //printf("Header 1: %s\n", getHeaderLabel(headerEntryOne));
    //printf("Header 2: %s\n", getHeaderLabel(headerEntryTwo));
    
    changeHeaderEntryLabel(headerEntryOne, headerThree);
    changeHeaderEntryLabel(headerEntryTwo, headerFour);
    //printf("Header 1: %s\n", getHeaderLabel(headerEntryOne));
    //printf("Header 2: %s\n", getHeaderLabel(headerEntryTwo));
    
    deleteHeaderEntryPtr(headerEntryOne);
    deleteHeaderEntryPtr(headerEntryTwo);
    
    return returnValue;
}

int runHeaderEntryListTests() {
    int returnValue = 0;
    
    char headerOne[] = {'O', 'n', 'e', '\0'};
    char headerTwo[] = {'T', 'w', 'o', '\0'};
    char headerThree[] = {'T', 'h', 'r', 'e', 'e', '\0'};
    char headerFour[] = {'F', 'o', 'u', 'r', '\0'};
    //char headerFive[] = {'F', 'i', 'v', 'e', '\0'};
    
    struct HeaderEntry *headerEntryHolder;
    
    struct HeaderEntry *headerEntryOne;
    headerEntryOne = makeHeaderEntryPtr(headerOne);
    
    struct HeaderEntry *headerEntryTwo;
    headerEntryTwo = makeHeaderEntryPtr(headerTwo);
    
    struct HeaderEntry *headerEntryThree;
    headerEntryThree = makeHeaderEntryPtr(headerThree);
    
    struct HeaderEntry *headerEntryFour;
    headerEntryFour = makeHeaderEntryPtr(headerFour);

    struct HeaderEntryList *headerEntryList = makeHeaderEntryListPtr();
    
    if(headerEntryList->size != 0) {
        printf("ERROR: StudentEntryList not properly constructed");
        returnValue++;
    }
    
    addHeaderEntry(headerEntryOne, headerEntryList);
    
    if(headerEntryList->size != 1) {
        printf("ERROR: HeaderEntryList not adding one correctly");
        returnValue++;
    }
    
    addHeaderEntry(headerEntryTwo, headerEntryList);
    
    if(headerEntryList->size != 2) {
        printf("ERROR: HeaderEntryList not adding two correctly");
        returnValue++;
    }
    
    addHeaderEntry(headerEntryThree, headerEntryList);
    
    if(headerEntryList->size != 3) {
        printf("ERROR: HeaderEntryList not adding three correctly");
        returnValue++;
    }
    
    addHeaderEntry(headerEntryFour, headerEntryList);
    
    if(headerEntryList->size != 4) {
        printf("ERROR: HeaderEntryList not adding four correctly");
        returnValue++;
    }
    
    int index;
    for(index = 0; index < 4; index++) {
        headerEntryHolder = getHeaderEntry(headerEntryList, index);
        //printf("Header at %i: %s\n", index, getHeaderLabel(headerEntryHolder));
    }
    
    for(index = 0; index < 2; index++) {
        headerEntryHolder = removeHeaderEntry(headerEntryList, index);
        //printf("Header at %i: %s\n", index, getHeaderLabel(headerEntryHolder));
        
        if(headerEntryList->size != (3 - index)) {
            printf("ERROR: HeaderEntryList not removing correctly\n");
            returnValue++;
        }
    }
    
    deleteHeaderEntryListPtr(headerEntryList);
    
    return returnValue;
}

int runTableTests() {
    int returnValue = 0;
    
    struct Table *tablePtr;
    tablePtr = makeTablePtr();
    
    char *headerOne = "Header1";
    struct HeaderEntry *headerEntryOne;
    headerEntryOne = makeHeaderEntryPtr(headerOne);
    
    char *headerTwo = "Header2";
    struct HeaderEntry *headerEntryTwo;
    headerEntryTwo = makeHeaderEntryPtr(headerTwo);
    
    char *headerThree = "Header3";
    struct HeaderEntry *headerEntryThree;
    headerEntryThree = makeHeaderEntryPtr(headerThree);
    
    char *headerFour = "Header4";
    struct HeaderEntry *headerEntryFour;
    headerEntryFour = makeHeaderEntryPtr(headerFour);
    
    if(tablePtr->headerEntryList->size != 0) {
        printf("ERROR: Table's HeaderEntryList not constructed correctly\n");
        returnValue++;
    }
    
    addHeaderEntryToTable(tablePtr, headerEntryOne);
    
    if(tablePtr->headerEntryList->size != 1) {
        printf("ERROR: Table's HeaderEntryList not adding correctly\n");
        returnValue++;
    }
    
    addHeaderEntryToTable(tablePtr, headerEntryTwo);
    addHeaderEntryToTable(tablePtr, headerEntryThree);
    addHeaderEntryToTable(tablePtr, headerEntryFour);
    
    if(tablePtr->students->size != 0) {
        printf("ERROR: Table's student list not constructed correctly\n");
        returnValue++;
    }
    
    char studentOneName[] = {'K', 'o', 'h', 'l', ' ', 'K', 'u', 'n', 't', 'z', 'e', '\0'};
    int idNumOne = 726111;
    
    struct StudentEntry *studentOne, *studentTwo, *holder;
    studentOne = makeStudentEntryPtr(studentOneName, idNumOne);
    
    addStudentEntryToTable(tablePtr, studentOne);
    
    if(tablePtr->students->size != 1) {
        printf("ERROR: Table's student list not adding correctly\n");
        returnValue++;
    }
    
    studentTwo = makeStudentEntryPtrFromUserInput(tablePtr->headerEntryList);
    addStudentEntryToTable(tablePtr, studentTwo);
    
    if(tablePtr->students->size != 2) {
        printf("ERROR: Table's student list not adding correctly\n");
        returnValue++;
    }
    
    holder = getStudentEntryFromTable(tablePtr, 1);
    
    printf("getStudentEntryFromTable got: %s\n", holder->studentName);
    
    holder = removeStudentEntryFromTable(tablePtr, 0);
    
    if(tablePtr->students->size != 1) {
        printf("ERROR: Table's student list not removing correctly\n");
        returnValue++;
    }
    
    deleteTablePtr(tablePtr);
    
    return returnValue;
}

int runAuxilaryFunctionsTests() {
    int returnValue = 0;
    
    char *headerOne = "Header1";
    char *headerTwo = "Header2";
    char *headerThree = "Header3";
    char *headerFour = "Header4";
    
    struct HeaderEntryList *headerEntryListPtr;
    headerEntryListPtr = makeHeaderEntryListPtr();
    
    struct HeaderEntry *headerEntryOne;
    headerEntryOne = makeHeaderEntryPtr(headerOne);
    addHeaderEntry(headerEntryOne, headerEntryListPtr);
    
    struct HeaderEntry *headerEntryTwo;
    headerEntryTwo = makeHeaderEntryPtr(headerTwo);
    addHeaderEntry(headerEntryTwo, headerEntryListPtr);
    
    struct HeaderEntry *headerEntryThree;
    headerEntryThree = makeHeaderEntryPtr(headerThree);
    addHeaderEntry(headerEntryThree, headerEntryListPtr);
    
    struct HeaderEntry *headerEntryFour;
    headerEntryFour = makeHeaderEntryPtr(headerFour);
    addHeaderEntry(headerEntryFour, headerEntryListPtr);
    
    struct StudentEntry *newStudent;
    newStudent = makeStudentEntryPtrFromUserInput(headerEntryListPtr);
    
    deleteStudentEntryPtr(newStudent);
    deleteHeaderEntryListPtr(headerEntryListPtr);
    
    return returnValue;
}

int runTests() {
    int returnValue = 0;
    returnValue = returnValue + runFloatArrayPointerTests();
    returnValue = returnValue + runStudentEntryTests();
    returnValue = returnValue + runStudentEntryListTests();
    returnValue = returnValue + runHeaderEntryTests();
    returnValue = returnValue + runHeaderEntryListTests();
    //returnValue = returnValue + runTableTests();
    returnValue = returnValue + runAuxilaryFunctionsTests();
    
    return returnValue;
}
