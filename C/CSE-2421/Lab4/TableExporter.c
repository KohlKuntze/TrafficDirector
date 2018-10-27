/*
 TableExporter.c
 Lab4
 
 Created by Kohl Kuntze on 9/28/18.
 Copyright © 2018 Kohl Kuntze. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"


void exportTableToFile(char *outputFilename, struct Table * table) {
    int counter, numOfStudents, rowCounter, dataCounter, scoreIndex;
    float currentScore;
    FILE *file;
    char *currentInfo;
    struct StudentEntry *currentStudent;
    struct HeaderEntry *currentHeader;
    
    printf("Table StudentList Size: %i\n", table->students->size);
    numOfStudents = table->students->size;
    
    if ((file = fopen(outputFilename, "w")) != NULL) {
        for(counter = 0; counter < NUM_OF_HEADERS; counter++) {
            currentHeader = getHeaderEntryFromTable(table, counter);
            currentInfo = getHeaderLabel(currentHeader);
            
            if(counter < (NUM_OF_HEADERS - 1)) {
                fprintf(file, "%s\t", currentInfo);
            } else {
                fprintf(file, "%s\n", currentInfo);
            }
        }
        
        for(counter = 0; counter < numOfStudents; counter++) {
            currentStudent = getStudentEntryFromTable(table, counter);
            fprintf(file, "%s\n", currentStudent->studentName);
            fprintf(file, "%i\n", currentStudent->studentId);
            scoreIndex = 0;
            for(rowCounter = 0; rowCounter < NUM_OF_HEADERS; rowCounter++) {
                for(dataCounter = 0; dataCounter < SCORES_PER_ROW; dataCounter++) {
                    currentScore = getFloat(currentStudent->grades, scoreIndex++);
                    
                    if(dataCounter < (SCORES_PER_ROW - 1)) {
                        printf("%.2f\t", currentScore);
                        fprintf(file, "%.2f\t", currentScore);
                    } else {
                        printf("%.2f\n", currentScore);
                        fprintf(file, "%.2f\n", currentScore);
                    }
                }
            }
        }
    }
    
    fclose(file);
}
