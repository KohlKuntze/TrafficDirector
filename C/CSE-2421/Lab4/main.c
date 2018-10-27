/*
 main.c
 Lab4

 Created by Kohl Kuntze on 9/28/18.
 Copyright © 2018 Kohl Kuntze. All rights reserved.
 */

#include "array.h"
#include <stdio.h>

char inputFile[] = "lab4input.txt";
char outputFile[] = "lab4output.txt";

int main(int argc, const char * argv[]) {
    printf("Will read from %s and write to %s\n\n", argv[1], argv[2]);
    
    manageTable(argv[1], argv[2]);
    //return runTests();
    return 0;
}
