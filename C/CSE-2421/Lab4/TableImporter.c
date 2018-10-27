/*
 TableImporter.c
 Lab4
 
 Created by Kohl Kuntze on 9/28/18.
 Copyright © 2018 Kohl Kuntze. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

const int NUM_OF_HEADERS = 4;
const int SCORES_PER_ROW = 3;
const int ROWS_PER_STUDENT = 6;

struct Table * importTableFromFile(char *inputFilename) {
    struct Table * table;
    FILE *file;
    char currentLine[NUM_OF_HEADERS][20];
    char firstName[40];
    char lastName[40];
    char currentChar;
    struct HeaderEntry *currentHeader;
    struct StudentEntry *newStudent;
    int counter;
    char space[2];
    int studentNum;
    float floatOne, floatTwo, floatThree;
    
    space[0] = ' ';
    space[1] = '\0';
    table = makeTablePtr();
    
    if ((file = fopen(inputFilename, "r")) != NULL) {
        
        fscanf(file,"%s %s %s %s", currentLine[0], currentLine[1], currentLine[2], currentLine[3]);
        
        for(counter = 0; counter < NUM_OF_HEADERS; counter++) {
            currentHeader = makeHeaderEntryPtr(currentLine[counter]);
            addHeaderEntry(currentHeader, table->headerEntryList);
        }
        
        while((fscanf(file,"%s", firstName)) != EOF) {
            fscanf(file,"%s\n", lastName);
            
            for(counter = 0; counter < 40; counter++) {
                currentChar = firstName[counter];
                if(!(currentChar >= 'A' && currentChar <= 'Z') && !(currentChar >= 'a' && currentChar <= 'z')) {
                    firstName[counter] = '\0';
                }
            }
            
            for(counter = 0; counter < 40; counter++) {
                currentChar = lastName[counter];
                if(!(currentChar >= 'A' && currentChar <= 'Z') && !(currentChar >= 'a' && currentChar <= 'z')) {
                    lastName[counter] = '\0';
                }
            }
            
            strcat(firstName, space);
            strcat(firstName, lastName);
            
            printf("Full name: %s\n", firstName);
            
            fscanf(file,"%i", &studentNum);
            
            
            newStudent = makeStudentEntryPtr(firstName, studentNum);
            
            for(counter = 0; counter < ROWS_PER_STUDENT - 2; counter++) {
                fscanf(file,"%f %f %f", &floatOne, &floatTwo, &floatThree);
                
                changeGrade(newStudent, floatOne, counter * 3);
                changeGrade(newStudent, floatTwo, counter * 3 + 1);
                changeGrade(newStudent, floatThree, counter * 3 + 2);
            }
            addStudentEntry(newStudent, table->students);
        }
    }
    
    fclose(file);
    
    return table;
}
