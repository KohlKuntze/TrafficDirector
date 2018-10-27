/* BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
 
 ** ALL OF THE CODE FOUND WITHIN THIS FILE WAS CREATED BY ME WITH NO
 
 ** ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
 
 ** OR ONE OF OUR UNDERGRADUATE GRADERS.
 
 ** lab4.h created by Kohl Kuntze
 
 */

#ifndef lab4_h
#define lab4_h

extern const int NUM_OF_HEADERS;
extern const int SCORES_PER_ROW;
extern const int ROWS_PER_STUDENT;

// ----- Float Array Stuff -----
struct FloatNode {
    float data;
    struct FloatNode* nextNode;
};

struct FloatList {
    int size;
    struct FloatNode* head;
};

struct FloatList* makeFloatListPtr();
void addFloat(struct FloatList * desiredList, float addedFloat);
float getFloat(struct FloatList * desiredList, int index);
void changeFloat(struct FloatList * desiredList, float newFloat, int index);
float removeFloat(struct FloatList * desiredList, int index);
void deleteFloatListPtr(struct FloatList * desiredList);

// ----- Student Entry Stuff -----
struct StudentEntry {
    char *studentName;
    int studentId;
    float finalGrade;
    struct FloatList* grades;
    struct StudentEntry* nextStudent;
};

struct StudentEntry* makeStudentEntryPtr(char * name, int studentIdentificationNum);
void changeGrade(struct StudentEntry * student, float newGrade, int index);
void deleteStudentEntryPtr(struct StudentEntry* student);
void calculateFinalGrade(struct StudentEntry* student);

//void addGrade(struct StudentEntry * desiredStudent, float grade, int index);

// ----- Student Entry List Stuff -----
struct StudentEntryList {
    int size;
    struct StudentEntry* headStudent;
};

struct StudentEntryList* makeStudentEntryListPtr();
void addStudentEntry(struct StudentEntry * newStudent, struct StudentEntryList * currentStudentEntryList);
struct StudentEntry * getStudentEntry(struct StudentEntryList * currentStudentEntryList, int index);
struct StudentEntry * removeStudentEntry(struct StudentEntryList * currentStudentEntryList, int index);
void deleteStudentEntryListPtr(struct StudentEntryList * list);

// ----- Header Entry Stuff -----
struct HeaderEntry {
    char *headerLabel;
    struct HeaderEntry* nextHeader;
};

struct HeaderEntry* makeHeaderEntryPtr(char * headerName);
void changeHeaderEntryLabel(struct HeaderEntry * headerEntry, char * newHeaderName);
char * getHeaderLabel(struct HeaderEntry * headerEntry);
void deleteHeaderEntryPtr(struct HeaderEntry* headerEntry);

// ----- Header Entry List Stuff -----
struct HeaderEntryList {
    int size;
    struct HeaderEntry* firstHeader;
};

struct HeaderEntryList* makeHeaderEntryListPtr();
void addHeaderEntry(struct HeaderEntry * newHeader, struct HeaderEntryList * list);
struct HeaderEntry * getHeaderEntry(struct HeaderEntryList * list, int index);
struct HeaderEntry * removeHeaderEntry(struct HeaderEntryList * list, int index);
void deleteHeaderEntryListPtr(struct HeaderEntryList * list);


// ----- Table Stuff -----
struct Table {
    struct HeaderEntryList* headerEntryList;
    struct StudentEntryList* students;
};

struct Table* makeTablePtr();
struct HeaderEntryList* getHeaderList(struct Table * table);
struct StudentEntryList* getStudentList(struct Table * table);
void addHeaderEntryToTable(struct Table * table, struct HeaderEntry * newHeader);
struct HeaderEntry * getHeaderEntryFromTable(struct Table * table, int index);
struct HeaderEntry * removeHeaderEntryFromTable(struct Table * table, int index);
void addStudentEntryToTable(struct Table * table, struct StudentEntry * newStudent);
struct StudentEntry * getStudentEntryFromTable(struct Table * table, int index);
struct StudentEntry * removeStudentEntryFromTable(struct Table * table, int index);
void deleteTablePtr(struct Table * table);

// ----- Table Management -----
void printHeaderInfo(struct Table * table);
void printByIdNumber(struct Table * table, int idNumber);
void printByLastName(struct Table * table, char *lastName);
void optionOne(struct Table * table);
void optionTwo(struct Table * table);
void optionThree(struct Table * table);
void optionFour(struct Table * table);
void optionFive(struct Table * table);
void optionSix(struct Table * table);
void optionSeven(struct Table * table);
void optionEight(struct Table * table);
void optionNine(struct Table * table);
void optionTen(struct Table * table);
void manageTable(char *inputFilename, char *outputFilename);

// ----- Import/Export Stuff -----
struct Table * importTableFromFile(char *inputFilename);
void exportTableToFile(char *outputFilename, struct Table * table);

// ----- Auxilary Functions -----

void getStringFromUser(char *prompt, char *returnString);
int getIntFromUser(char *prompt);
float getFloatFromUser(char *prompt);

void printGrades(struct StudentEntry * student);
struct StudentEntry * makeStudentEntryPtrFromUserInput(struct HeaderEntryList * headerEntryList);

#endif /* lab4_h */
