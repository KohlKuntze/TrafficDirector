/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** calculateSubscore.c created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

// Calculate cumulative subscores
void calculateSubscore(float * categoryPointer, int pointerStart, struct FloatList * grades, int gradesStart) {
    float currentGrade;
    float categoryScoresTemp[4], sum;
    int index, numOfScores;
    float average;
    
    numOfScores = 0;
    sum = 0;
    
    // Get relevant scores
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
    
    // Return scores
    for(index = 0; index < 4; index++) {
        *(categoryPointer + pointerStart + index) = categoryScoresTemp[index];
    }
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
    
    // Get cumulatives
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
    
    // Assign final grade
    student->finalGrade = finalSum;
}
