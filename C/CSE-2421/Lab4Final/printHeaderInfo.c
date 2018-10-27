/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** printHeaderInfo.c created by Kohl Kuntze
 
 */


#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

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
    
    printf("%s\t\t\t%s\t", studentNameHeader, studentIdHeader);
    
    // print headers with consistent spacing
    for(counter = 0; counter < 4; counter++) {
        printf("%-32s", getHeaderLabel(getHeaderEntry(headerList, counter)));
    }
    
    // print current and final
    printf("%-10s", current);
    printf("%-6s\n", final);
    
    // tabs
    printf("\t\t\t\t\t\t");
    for(counter = 0; counter < 4; counter++) {
        printf("1\t2\t3\tCum\t");
    }
    
    // print word grades
    printf("%-10s", grade);
    printf("%s\n", grade);
}
