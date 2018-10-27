/*
 DatabaseManager.c
 Lab4
 
 Created by Kohl Kuntze on 9/28/18.
 Copyright © 2018 Kohl Kuntze. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

void printHeaderInfo(struct Table * table) {
    struct HeaderEntryList *headerList;
    int counter;
    char *studentNameHeader, *studentIdHeader, *current, *final, *grade;
    studentNameHeader = "Student Name";
    studentIdHeader = "Student ID#";
    current = "Current";
    final = "Final";
    grade = "Grade";
    
    headerList = table->headerEntryList;
    
    printf("%s     %s\t", studentNameHeader, studentIdHeader);
    
    for(counter = 0; counter < 4; counter++) {
        printf("%s\t\t\t\t", getHeaderLabel(getHeaderEntry(headerList, counter)));
    }
    printf("\t%s\t", current);
    printf("%s\n", final);
    
    printf("\t\t\t\t");
    for(counter = 0; counter < 4; counter++) {
        printf("1\t2\t3\tCum\t");
    }
    printf("%s\t", grade);
    printf("%s\n", grade);
    
    
}

void printByIdNumber(struct Table * table, int idNumber) {
    struct StudentEntry *studentEntryPtr;
    int index;
    for(index = 0; index < table->students->size; index++) {
        studentEntryPtr = getStudentEntry(table->students, index);
        if (studentEntryPtr->studentId == idNumber) {
            printGrades(studentEntryPtr);
        }
    }
}

void printByLastName(struct Table * table, char *lastName) {
    int index;
    struct StudentEntry *studentEntryPtr;
    char *currentLastName;
    
    for(index = 0; index < table->students->size; index++) {
        studentEntryPtr = getStudentEntry(table->students, index);
        currentLastName = studentEntryPtr->studentName;
        
        if(strstr(currentLastName, lastName) != NULL) {
            printGrades(studentEntryPtr);
        }
    }
}

void optionOne(struct Table * table) {
    char *prompt;
    int studentId;
    
    prompt = "Input the ID number of the student whose grades you'd like to see:";
    studentId = getIntFromUser(prompt);
    printf("\n");
    
    printHeaderInfo(table);
    printByIdNumber(table, studentId);
}

void optionTwo(struct Table * table) {
    char *prompt;
    char studentLastName[40];
    
    prompt = "Input the last name of the student whose grades you'd like to see:";
    
    getStringFromUser(prompt, studentLastName);
    printf("\n");
    
    printHeaderInfo(table);
    printByLastName(table, studentLastName);
}

void optionThree(struct Table * table) {
    int mostRecentlyPrintedInt, highestInt;
    int outerCounter, innerCounter;
    struct StudentEntry *studentEntryPtr;
    
    mostRecentlyPrintedInt = -1;
    highestInt = -1;
    
    printHeaderInfo(table);
    
    for(outerCounter = 0; outerCounter < table->students->size; outerCounter++) {
        highestInt = 2147483647;
        for (innerCounter = 0; innerCounter < table->students->size; innerCounter ++) {
            studentEntryPtr = getStudentEntry(table->students, innerCounter);
            
            if(studentEntryPtr->studentId > mostRecentlyPrintedInt && studentEntryPtr->studentId <= highestInt) {
                highestInt = studentEntryPtr->studentId;
            }
        }
        
        printByIdNumber(table, highestInt);
        mostRecentlyPrintedInt = highestInt;
    }
}

void optionFour(struct Table * table) {
    char *prompt;
    int studentId;
    struct StudentEntry *studentEntryPtr;
    int index;
    
    prompt = "Input the ID number of the student whose grades you'd like to recalculate:";
    studentId = getIntFromUser(prompt);
    printf("\n");
    
    for(index = 0; index < table->students->size; index++) {
        studentEntryPtr = getStudentEntry(table->students, index);
        if (studentEntryPtr->studentId == studentId) {
            calculateFinalGrade(studentEntryPtr);
        }
    }
    
    printHeaderInfo(table);
    printByIdNumber(table, studentId);
}

void optionFive(struct Table * table) {
    optionThree(table);
}

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

int getSubScoreIndex() {
    int option;
    char *prompt;
    prompt = "Which subscore would you like to change (1-3):";
    option = getIntFromUser(prompt);
    return --option;
}

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
    
    prompt = "Input the ID number of the student whose grades you'd like to edit:";
    studentId = getIntFromUser(prompt);
    
    category = getCategory(table);
    scoreIndex = getSubScoreIndex();
    newGrade = getNewGrade();
    
    
    for(index = 0; index < table->students->size; index++) {
        studentEntryPtr = getStudentEntry(table->students, index);
        if (studentEntryPtr->studentId == studentId) {
            changeGrade(studentEntryPtr, newGrade, 3 * category + scoreIndex);
        }
    }
}

void optionSeven(struct Table * table) {
    struct StudentEntry *studentEntryPtr;
    int index;
    printHeaderInfo(table);
    
    for(index = 0; index < table->students->size; index++) {
        studentEntryPtr = getStudentEntry(table->students, index);
        calculateFinalGrade(studentEntryPtr);
        printByIdNumber(table, studentEntryPtr->studentId);
    }
}

void optionEight(struct Table * table) {
    struct StudentEntry *newStudent;
    newStudent = makeStudentEntryPtrFromUserInput(table->headerEntryList);
    addStudentEntryToTable(table, newStudent);
}

void optionNine(struct Table * table) {
    int index, indexOfStudentToRemove;
    struct StudentEntry *removedStudent, *currentStudent;
    char *prompt;
    int studentId;
    
    prompt = "Input the ID number of the student who you'd like to remove:";
    indexOfStudentToRemove = -1;
    
    studentId = getIntFromUser(prompt);
    printf("\n");
    
    for(index = 0; index < table->students->size; index++) {
        currentStudent = getStudentEntry(table->students, index);
        if(currentStudent->studentId == studentId) {
            indexOfStudentToRemove = index;
        }
    }
    
    removedStudent = removeStudentEntryFromTable(table, indexOfStudentToRemove);
    deleteStudentEntryPtr(removedStudent);
}

void optionTen(struct Table * table) {
    deleteTablePtr(table);
}

int getOptionFromUser() {
    int option;
    char *prompt;
    printf("Please enter an option between 1 and 10:\n");
    printf("1)  Print Student Scores by Student ID\n");
    printf("2)  Print Student Scores by Last Name\n");
    printf("3)  Print Student Scores for All Students\n");
    printf("4)  Recalculate Student Scores for a Single Student ID\n");
    printf("5)  Recalculate All Student Scores\n");
    printf("6)  Insert a score for a specific Student ID\n");
    printf("7)  Calculate Final Grades\n");
    printf("8)  Add a new student\n");
    printf("9)  Delete a student\n");
    printf("10) Exit Program\n");
    
    option = 10;
    prompt = "input desired command:";
    option = getIntFromUser(prompt);
    return option;
}

void manageTable(char *inputFilename, char *outputFilename) {
    int option = -1;
    struct Table * table;
    table = importTableFromFile(inputFilename);
    while(option < 10) {
        option = getOptionFromUser();
        switch (option) {
            case 1:
                optionOne(table);
                break;
            case 2:
                optionTwo(table);
                break;
            case 3:
                optionThree(table);
                break;
            case 4:
                optionFour(table);
                break;
            case 5:
                optionFive(table);
                break;
            case 6:
                optionSix(table);
                break;
            case 7:
                optionSeven(table);
                break;
            case 8:
                optionEight(table);
                break;
            case 9:
                optionNine(table);
                break;
            default:
                exportTableToFile(outputFilename, table);
                optionTen(table);
                break;
        }
    }
}
