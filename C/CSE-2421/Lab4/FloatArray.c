/*
 FloatArray.c
 Lab4
 
 Created by Kohl Kuntze on 9/28/18.
 Copyright © 2018 Kohl Kuntze. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

struct FloatList* makeFloatListPtr() {
    struct FloatList *listPtr = (struct FloatList*) malloc(sizeof(struct FloatList));
    listPtr->size = 0;
    listPtr->head = NULL;
    
    return listPtr;
}

void addFloat(struct FloatList * desiredList, float addedFloat) {
    struct FloatNode* newNode;
    struct FloatNode* current;
    int counter;
    
    newNode = (struct FloatNode*) malloc(sizeof(struct FloatNode));
    newNode->data = addedFloat;
    
    if(desiredList->size == 0) {
        desiredList->head = newNode;
        desiredList->head->nextNode = NULL;
    } else {
        current = desiredList->head;
        counter = 0;
        
        while((desiredList->size - 1) > counter++) current = current->nextNode;
        
        current->nextNode = newNode;
        current->nextNode->nextNode = NULL;
    }
    
    desiredList->size = desiredList->size + 1;
}

float getFloat(struct FloatList * desiredList, int index) {
    struct FloatList floatList;
    struct FloatNode *current;
    int counter;
    float data;
    
    floatList = *desiredList;
    current = floatList.head;
    counter = 0;
    
    while(index > counter++) current = (*current).nextNode;
    data = (*current).data;
    
    return data;
}

void changeFloat(struct FloatList * desiredList, float newFloat, int index) {
    struct FloatNode* current;
    int counter;
    
    current = desiredList->head;
    counter = 0;

    
    while(index > counter++) current = current->nextNode;
    
    current->data = newFloat;
}

float removeFloat(struct FloatList * desiredList, int index) {
    int counter;
    struct FloatNode *removedNode, *temp;
    float tempValue;
    
    if(index <= desiredList->size && index >=0) {
        temp = desiredList->head;
        
        if(index == 0) {
            desiredList->head = desiredList->head->nextNode;
            tempValue = temp->data;
            free(temp);
        }else{
            counter = 0;
            while((index - 1) > counter++) temp = temp->nextNode;
            
            tempValue = temp->nextNode->data;
            removedNode = temp->nextNode;
            temp->nextNode = temp->nextNode->nextNode;
            free(removedNode);
        }
        
        desiredList->size = desiredList->size - 1;
        return tempValue;
    } else {
        return 0;
    }
}

void deleteFloatListPtr(struct FloatList * desiredList) {
    while (desiredList->size > 0) {
        removeFloat(desiredList, 0);
    }
    
    free(desiredList);
}
