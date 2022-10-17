#pragma once
#include <iostream>

#define MAX_WORD_LENGTH 15

using namespace std;

char text[];

void runEngine(void);

void readText(void);

char** getFinalizedCommands(void);

// verbosity is not done yet
char** parseText(const char* text, bool verbose = true);

char* processSubText(int i, int* next_space_index, bool verbose = true);

int getTotalWords(const char* text);

void registerSubCommands( const char* sub_text, char** split_texts, int index, bool verbose = true);

void finalizeSubCommands( char** split_texts, int index, bool verbose = true );