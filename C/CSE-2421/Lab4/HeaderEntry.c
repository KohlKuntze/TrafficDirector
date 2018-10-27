/*
 HeaderEntry.c
 Lab4
 
 Created by Kohl Kuntze on 9/28/18.
 Copyright © 2018 Kohl Kuntze. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

struct HeaderEntry* makeHeaderEntryPtr(char * headerLabel) {
    struct HeaderEntry* headerEntry;
    char *labelPtr;
    
    headerEntry = (struct HeaderEntry *) malloc(sizeof(struct HeaderEntry));
    labelPtr = (char *) malloc(sizeof(char *));
    strcpy(labelPtr, headerLabel);
    
    headerEntry->headerLabel = labelPtr;
    headerEntry->nextHeader = NULL;
    
    return headerEntry;
}

void changeHeaderEntryLabel(struct HeaderEntry * headerEntry, char * newHeaderName) {
    free(headerEntry->headerLabel);
    
    char *labelPtr;
    labelPtr = (char *) malloc(sizeof(char *));
    strcpy(labelPtr, newHeaderName);
    
    headerEntry->headerLabel = labelPtr;
}

char * getHeaderLabel(struct HeaderEntry * headerEntry) {
    char *labelPtr;
    labelPtr = headerEntry->headerLabel;
    
    return labelPtr;
}

void deleteHeaderEntryPtr(struct HeaderEntry* headerEntry) {
    free(headerEntry->headerLabel);
    free(headerEntry);
}
