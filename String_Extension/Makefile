# comment
CC= g++
CFLAG= -c -Wall

all: main.o src/String_Ext.o
	$(CC) main.o src/String_Ext.o -o main

main.o: main.cpp
	$(CC) $(CFLAG) main.cpp

String_Ext.o: src/String_Ext.cpp
	$(CC) $(CFLAG) src/String_Ext.cpp

clear: 
	rm -rf *o src/String_Ext.o main			