/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** importTableFromFile.c created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab4.h"

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
    
    // open file
    if ((file = fopen(inputFilename, "r")) != NULL) {
        
        // get 4 headers
        fscanf(file,"%s %s %s %s", currentLine[0], currentLine[1], currentLine[2], currentLine[3]);
        
        // add headers to list
        for(counter = 0; counter < NUM_OF_HEADERS; counter++) {
            currentHeader = makeHeaderEntryPtr(currentLine[counter]);
            addHeaderEntry(currentHeader, table->headerEntryList);
        }
        
        // get students until EOF
        while((fscanf(file,"%s", firstName)) != EOF) {
            fscanf(file,"%s\n", lastName);
            
            // clean input of first name
            for(counter = 0; counter < 40; counter++) {
                currentChar = firstName[counter];
                if(!(currentChar >= 'A' && currentChar <= 'Z') && !(currentChar >= 'a' && currentChar <= 'z')) {
                    firstName[counter] = '\0';
                }
            }
            
            // clean input of second name
            for(counter = 0; counter < 40; counter++) {
                currentChar = lastName[counter];
                if(!(currentChar >= 'A' && currentChar <= 'Z') && !(currentChar >= 'a' && currentChar <= 'z')) {
                    lastName[counter] = '\0';
                }
            }
            
            strcat(firstName, space);
            strcat(firstName, lastName);
            
            // get student ID
            fscanf(file,"%i", &studentNum);
            
            // Make student
            newStudent = makeStudentEntryPtr(firstName, studentNum);
            
            // add grades
            for(counter = 0; counter < ROWS_PER_STUDENT - 2; counter++) {
                fscanf(file,"%f %f %f", &floatOne, &floatTwo, &floatThree);
                
                changeGrade(newStudent, floatOne, counter * 3);
                changeGrade(newStudent, floatTwo, counter * 3 + 1);
                changeGrade(newStudent, floatThree, counter * 3 + 2);
            }
            addStudentEntry(newStudent, table->students);
        }
    }
    
    // close file
    fclose(file);
    
    return table;
}
