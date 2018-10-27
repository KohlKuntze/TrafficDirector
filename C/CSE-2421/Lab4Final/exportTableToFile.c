/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** exportTableToFile.c created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab4.h"

void exportTableToFile(char *outputFilename, struct Table * table) {
    int counter, numOfStudents, rowCounter, dataCounter, scoreIndex;
    float currentScore;
    FILE *file;
    char *currentInfo;
    struct StudentEntry *currentStudent;
    struct HeaderEntry *currentHeader;
    
    numOfStudents = table->students->size;
    
    // Open file
    if ((file = fopen(outputFilename, "w")) != NULL) {
        
        // Print headers
        for(counter = 0; counter < NUM_OF_HEADERS; counter++) {
            currentHeader = getHeaderEntryFromTable(table, counter);
            currentInfo = getHeaderLabel(currentHeader);
            
            if(counter < (NUM_OF_HEADERS - 1)) {
                fprintf(file, "%s\t", currentInfo);
            } else {
                fprintf(file, "%s\n", currentInfo);
            }
        }
        
        // Print students
        for(counter = 0; counter < numOfStudents; counter++) {
            currentStudent = getStudentEntryFromTable(table, counter);
            
            // name
            fprintf(file, "%s\n", currentStudent->studentName);
            
            // id
            fprintf(file, "%i\n", currentStudent->studentId);
            scoreIndex = 0;
            
            // grades
            for(rowCounter = 0; rowCounter < NUM_OF_HEADERS; rowCounter++) {
                for(dataCounter = 0; dataCounter < SCORES_PER_ROW; dataCounter++) {
                    currentScore = getFloat(currentStudent->grades, scoreIndex++);
                    
                    if(dataCounter < (SCORES_PER_ROW - 1)) {
                        fprintf(file, "%.2f\t", currentScore);
                    } else {
                        fprintf(file, "%.2f\n", currentScore);
                    }
                }
            }
        }
    }
    
    // close file
    fclose(file);
}
