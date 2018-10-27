/*
 StudentEntry.c
 Lab4
 
 Created by Kohl Kuntze on 9/28/18.
 Copyright © 2018 Kohl Kuntze. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

void calculateSubscore(float * categoryPointer, int pointerStart, struct FloatList * grades, int gradesStart) {
    float currentGrade;
    float categoryScoresTemp[4], sum;
    int index, numOfScores;
    float average;
    
    numOfScores = 0;
    sum = 0;
    
    for(index = 0; index < 4; index++) {
        if(index < 3) {
            currentGrade = getFloat(grades, gradesStart + index);
            categoryScoresTemp[index] = currentGrade;
            numOfScores++;
            sum += currentGrade;
        } else {
            if(numOfScores == 0) {
                categoryScoresTemp[index] = -1;
            } else {
                average = sum / numOfScores;
                categoryScoresTemp[index] = average;
            }
        }
    }
    
    for(index = 0; index < 4; index++) {
        *(categoryPointer + pointerStart + index) = categoryScoresTemp[index];
    }
}

void printGrades(struct StudentEntry * student) {
    float currentPrintValue;
    int cumulativesFound;
    float currentSum;
    float currentCum;
    float weights[NUM_OF_HEADERS];
    struct FloatList *gradesPtr;
    int i;
    float gradeReportArray[17];
    
    gradesPtr = student->grades;
    
    for (i = 0; i < 4; i++) {
        calculateSubscore(gradeReportArray, i * 4, gradesPtr, i * 3);
    }
    
    currentSum = 0;
    cumulativesFound = 0;
    weights[0] = 0.15f;
    weights[1] = 0.3f;
    weights[2] = 0.2f;
    weights[3] = 0.35f;
    printf("%-40s\t", student->studentName);
    printf("%6i\t", student->studentId);
    
    for(i = 0; i < 4; i++) {
        currentCum = gradeReportArray[i * 4 + 3];
        if(currentCum >= 0) {
            currentSum += weights[i] * currentCum;
            cumulativesFound++;
        } else {
            currentSum += weights[i] * 100.0;
        }
    }
    
    gradeReportArray[16] = currentSum;
    
    for(i = 0; i < 18; i++) {
        if(i < 17) {
            currentPrintValue = gradeReportArray[i];
        }else {
            currentPrintValue = student->finalGrade;
        }
        
        if(currentPrintValue < 0) {
            printf("n/a\t");
        } else {
            printf("%.2f\t", currentPrintValue);
        }
    }
    
    printf("\n");
}

void calculateFinalGrade(struct StudentEntry* student) {
    float gradeReportArray[17];
    int i;
    float finalSum ;
    float currentCum;
    float weights[NUM_OF_HEADERS];
    int cumulativesFound;
    struct FloatList *gradesPtr;
    gradesPtr = student->grades;
    weights[0] = 0.15f;
    weights[1] = 0.3f;
    weights[2] = 0.2f;
    weights[3] = 0.35f;
    
    for (i = 0; i < 4; i++) {
        calculateSubscore(gradeReportArray, i * 4, gradesPtr, i * 3);
    }
    
    finalSum = 0;
    cumulativesFound = 0;
    
    for(i = 0; i < 4; i++) {
        currentCum = gradeReportArray[i * 4 + 3];
        if(currentCum >= 0) {
            finalSum += weights[i] * currentCum;
            cumulativesFound++;
        } else {
            finalSum += 0;
        }
    }
    
    student->finalGrade = finalSum;
}

struct StudentEntry* makeStudentEntryPtr(char * name, int studentIdentificationNum) {
    struct StudentEntry* student;
    char *namePtr;
    int counter;
    
    namePtr = (char *) malloc(40 * sizeof(char *));
    student = (struct StudentEntry *) malloc(sizeof(struct StudentEntry));
    strcpy(namePtr, name);
    
    student->studentName = namePtr;
    
    student->grades = makeFloatListPtr();
    
    for(counter = 0; counter < 12; counter++) {
        addFloat(student->grades, -1.00);
    }
    
    student->studentId = studentIdentificationNum;
    student->nextStudent = NULL;
    student->finalGrade = -1.00f;
    
    return student;
}

void changeGrade(struct StudentEntry * student, float newGrade, int index) {
    struct FloatList* gradeList;
    gradeList = student->grades;
    changeFloat(gradeList, newGrade, index);
}

void deleteStudentEntryPtr(struct StudentEntry* student) {
    free(student->studentName);
    deleteFloatListPtr(student->grades);
    free(student);
}
