#include <iostream>

#include "TextParser.h"

int main() {
	
	while ("program is alive") {
		runEngine("Command: ", false);
		char** parsedCommands = getFinalizedCommands();

		if (parsedCommands == NULL) {
			printf("No commands\n");
		}

		int count = 0;
		for (int i = 0; parsedCommands[i] != NULL; i++) {
			count++;
		}

		printf("Total sub commands: %d\n", count);

		if (count == 2) {
			//printf("2 words command\n");
			if (strcmp(parsedCommands[0], "hello") == 0 && strcmp(parsedCommands[1], "world") == 0) {
				printf("Executing `hello world`...\n");
			}
		}
		else if (count ==1) {
			if (strcmp(parsedCommands[0], "q") == 0) {
				return 10;
			}
		}

		// free
		for (int i = 0; i < count; i++) {
			free(parsedCommands[i]);
		}
		//free(parsedCommands);


		/*
		// https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
		int maxWordLength = 15;
		// do checking for individual split word, if > maxWordLength => command not supported
		char** split_texts = (char**)malloc( sizeof(char*) );
		split_texts[0] = (char*)malloc( maxWordLength * sizeof(char*) + 1 );
		strcpy_s(split_texts[0], maxWordLength+1, "hello");

		printf( "%s\n", split_texts[0]);
		*/
	}
	

	return 0;
}