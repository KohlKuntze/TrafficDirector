/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** addStudentEntryToTable.c created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

void addStudentEntryToTable(struct Table * table, struct StudentEntry * newStudent) {
    // Call helper function
    addStudentEntry(newStudent, table->students);
}
