/*
 Table.c
 Lab4
 
 Created by Kohl Kuntze on 9/28/18.
 Copyright © 2018 Kohl Kuntze. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

struct Table* makeTablePtr() {
    struct Table *table;
    table = (struct Table *) malloc(sizeof(struct Table));
    table->students = makeStudentEntryListPtr();
    table->headerEntryList = makeHeaderEntryListPtr();
    
    return table;
}

struct HeaderEntryList* getHeaderList(struct Table * table) {
    struct HeaderEntryList *headerListPtr;
    headerListPtr = table->headerEntryList;
    
    return headerListPtr;
}

struct StudentEntryList* getStudentList(struct Table * table) {
    struct StudentEntryList *studentListPtr;
    studentListPtr = table->students;
    return studentListPtr;
}

void addHeaderEntryToTable(struct Table * table, struct HeaderEntry * newHeader) {
    addHeaderEntry(newHeader, table->headerEntryList);
}

struct HeaderEntry * getHeaderEntryFromTable(struct Table * table, int index) {
    return getHeaderEntry(table->headerEntryList, index);
}

struct HeaderEntry * removeHeaderEntryFromTable(struct Table * table, int index) {
    return removeHeaderEntry(table->headerEntryList, index);
}

void addStudentEntryToTable(struct Table * table, struct StudentEntry * newStudent) {
    addStudentEntry(newStudent, table->students);
}

struct StudentEntry * getStudentEntryFromTable(struct Table * table, int index) {
    return getStudentEntry(table->students, index);
}

struct StudentEntry * removeStudentEntryFromTable(struct Table * table, int index) {
    return removeStudentEntry(table->students, index);
}

void deleteTablePtr(struct Table * table) {
    deleteHeaderEntryListPtr(table->headerEntryList);
    deleteStudentEntryListPtr(table->students);
    free(table);
}
