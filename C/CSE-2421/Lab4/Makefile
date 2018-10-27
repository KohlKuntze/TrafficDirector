all: lab4

lab4: main.o FloatArray.o StudentEntry.o StudentEntryList.o HeaderEntry.o HeaderEntryList.o Table.o TableImporter.o DatabaseManager.o AuxilaryFunctions.o  TableExporter.o test.o
	gcc main.o FloatArray.o StudentEntry.o StudentEntryList.o HeaderEntry.o HeaderEntryList.o Table.o TableImporter.o DatabaseManager.o AuxilaryFunctions.o  TableExporter.o test.o -o lab4

main.o: main.c array.h
	gcc -ansi -pedantic -c main.c

FloatArray.o: FloatArray.c array.h
	gcc -ansi -pedantic -c FloatArray.c

StudentEntry.o: StudentEntry.c array.h
	gcc -ansi -pedantic -c StudentEntry.c

StudentEntryList.o: StudentEntryList.c array.h
	gcc -ansi -pedantic -c StudentEntryList.c

HeaderEntry.o: HeaderEntry.c array.h
	gcc -ansi -pedantic -c HeaderEntry.c

HeaderEntryList.o: HeaderEntryList.c array.h
	gcc -ansi -pedantic -c HeaderEntryList.c

Table.o: Table.c array.h
	gcc -ansi -pedantic -c Table.c

TableImporter.o: TableImporter.c array.h
	gcc -ansi -pedantic -c TableImporter.c

DatabaseManager.o: DatabaseManager.c array.h
	gcc -ansi -pedantic -c DatabaseManager.c

AuxilaryFunctions.o: AuxilaryFunctions.c array.h
	gcc -ansi -pedantic -c AuxilaryFunctions.c

TableExporter.o: TableExporter.c array.h
	gcc -ansi -pedantic -c TableExporter.c

test.o: test.c array.h
	gcc -ansi -pedantic -c test.c

clean:
	rm -rf *.o lab4