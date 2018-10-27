/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** manageTable.c created by Kohl Kuntze
 
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

// function to get option number
int getOptionFromUser() {
    int option;
    char *prompt;
    printf("Please enter an option between 1 and 10:\n");
    printf("1)  Print Student Scores by Student ID\n");
    printf("2)  Print Student Scores by Last Name\n");
    printf("3)  Print Student Scores for All Students\n");
    printf("4)  Recalculate Student Scores for a Single Student ID\n");
    printf("5)  Recalculate All Student Scores\n");
    printf("6)  Insert a score for a specific Student ID\n");
    printf("7)  Calculate Final Grades\n");
    printf("8)  Add a new student\n");
    printf("9)  Delete a student\n");
    printf("10) Exit Program\n");
    
    option = 10;
    prompt = "input desired command:";
    option = getIntFromUser(prompt);
    return option;
}

void manageTable(char *inputFilename, char *outputFilename) {
    int option = -1;
    struct Table * table;
    void (*fun_ptrs[10])(struct Table *table);
    // ptrs to function
    fun_ptrs[0] = optionOne;
    fun_ptrs[1] = optionTwo;
    fun_ptrs[2] = optionThree;
    fun_ptrs[3] = optionFour;
    fun_ptrs[4] = optionFive;
    fun_ptrs[5] = optionSix;
    fun_ptrs[6] = optionSeven;
    fun_ptrs[7] = optionEight;
    fun_ptrs[8] = optionNine;
    fun_ptrs[9] = optionTen;

    table = importTableFromFile(inputFilename);
    
    // go until 10 (exit command)
    while(option < 10) {
        option = getOptionFromUser();
        if(option == 10) {
            // export before deleting
            exportTableToFile(outputFilename, table);
        }
        
        fun_ptrs[option - 1](table);
    }
}
