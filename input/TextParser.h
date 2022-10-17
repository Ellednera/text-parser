#pragma once
#include <iostream>

using namespace std;

char text[];
char* sub_strings[];

void runEngine(void);

void readText(void);

// verbosity is not done yet
char** parseText(const char* text, bool verbose = true);

char* processSubText(int i, int* next_space_index, bool verbose = true);

int getTotalWords(const char* text);
