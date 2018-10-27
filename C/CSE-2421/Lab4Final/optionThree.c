/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** optionThree.c created by Kohl Kuntze
 
 */


#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

void optionThree(struct Table * table) {
    int mostRecentlyPrintedInt, highestInt;
    int outerCounter, innerCounter;
    struct StudentEntry *studentEntryPtr;
    
    mostRecentlyPrintedInt = -1;
    highestInt = -1;
    
    printHeaderInfo(table);
    
    // prints sequentially
    for(outerCounter = 0; outerCounter < table->students->size; outerCounter++) {
        highestInt = 2147483647;
        for (innerCounter = 0; innerCounter < table->students->size; innerCounter ++) {
            studentEntryPtr = getStudentEntry(table->students, innerCounter);
            
            // gets next highest id number
            if(studentEntryPtr->studentId > mostRecentlyPrintedInt && studentEntryPtr->studentId <= highestInt) {
                highestInt = studentEntryPtr->studentId;
            }
        }
        
        // prints out next entry
        printByIdNumber(table, highestInt);
        mostRecentlyPrintedInt = highestInt;
    }
}
