/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** printGrades.c created by Kohl Kuntze
 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab4.h"

// calculates subscore helper function
void getSubscore(float * categoryPointer, int pointerStart, struct FloatList * grades, int gradesStart) {
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

// prints grades of student
void printGrades(struct StudentEntry * student) {
    float currentPrintValue;
    int cumulativesFound;
    float currentSum;
    float currentCum;
    float weights[NUM_OF_HEADERS];
    struct FloatList *gradesPtr;
    int i;
    float gradeReportArray[17];
    char notApp[4];
    
    notApp[0] = 'n';
    notApp[1] = '/';
    notApp[2] = 'a';
    notApp[3] = '\0';
    
    gradesPtr = student->grades;
    
    for (i = 0; i < 4; i++) {
        getSubscore(gradeReportArray, i * 4, gradesPtr, i * 3);
    }
    
    // weights
    currentSum = 0;
    cumulativesFound = 0;
    weights[0] = 0.15f;
    weights[1] = 0.3f;
    weights[2] = 0.2f;
    weights[3] = 0.35f;
    
    // correct formatting
    printf("%-30s ", student->studentName);
    printf("%6i\t\t", student->studentId);
    
    // gets cumulative scores
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
    
    // prints grades
    for(i = 0; i < 18; i++) {
        if(i < 17) {
            currentPrintValue = gradeReportArray[i];
        }else {
            currentPrintValue = student->finalGrade;
        }
        
        if(currentPrintValue < 0) {
            printf("%5s\t", notApp);
        } else {
            printf("%5.2f\t", currentPrintValue);
        }
    }
    
    printf("\n");
}
