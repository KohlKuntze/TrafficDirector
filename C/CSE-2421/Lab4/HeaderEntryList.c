/*
 HeaderEntryList.c
 Lab4
 
 Created by Kohl Kuntze on 9/28/18.
 Copyright © 2018 Kohl Kuntze. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

struct HeaderEntryList* makeHeaderEntryListPtr() {
    struct HeaderEntryList *headerEntryList;
    headerEntryList = (struct HeaderEntryList *) malloc(sizeof(struct HeaderEntryList));
    headerEntryList->size = 0;
    headerEntryList->firstHeader = NULL;
    
    return headerEntryList;
}

void addHeaderEntry(struct HeaderEntry * newHeader, struct HeaderEntryList * list) {
    struct HeaderEntry *currentHeader;
    
    if(list->size == 0) {
        list->firstHeader = newHeader;
    } else {
        currentHeader = list->firstHeader;
        while(currentHeader->nextHeader != NULL) currentHeader = currentHeader->nextHeader;
        
        currentHeader->nextHeader = newHeader;
    }
    
    list->size = list->size + 1;
}

struct HeaderEntry * getHeaderEntry(struct HeaderEntryList * list, int index) {
    struct HeaderEntry *headerEntryPtr;
    int counter;
    
    headerEntryPtr = list->firstHeader;
    counter = 0;
    
    while(index > counter++) headerEntryPtr = headerEntryPtr->nextHeader;
    
    return headerEntryPtr;
}

struct HeaderEntry * removeHeaderEntry(struct HeaderEntryList * list, int index) {
    struct HeaderEntry *returnHeaderPtr;
    int counter;
    struct HeaderEntry *temp;
    
    returnHeaderPtr = NULL;
    
    if(index < list->size) {
        if (list->size == 1 || index == 0) {
            returnHeaderPtr = list->firstHeader;
            list->firstHeader = list->firstHeader->nextHeader;
        } else {
            temp = list->firstHeader;
            counter = 0;
            
            while((index - 1) > counter++) temp = temp->nextHeader;
            
            returnHeaderPtr = temp->nextHeader;
            temp->nextHeader = temp->nextHeader->nextHeader;
        }
        
        list->size = list->size - 1;
    }
    
    return returnHeaderPtr;
}

void deleteHeaderEntryListPtr(struct HeaderEntryList * list) {
    struct HeaderEntry *headerEntryPtr;
    
    while(list->size > 0) {
        headerEntryPtr = removeHeaderEntry(list, 0);
        deleteHeaderEntryPtr(headerEntryPtr);
    }
    
    free(list);
}
