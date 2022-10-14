#include "TextParser.h"

#define MAX_TEXT_LENGTH 50

char text[MAX_TEXT_LENGTH] = "";
char* sub_strings[] = { NULL };

void runEngine(void) {
	readText();
}

void readText(void) {

	printf("Type something: ");
	gets_s(text);

	parseText(text);
}

char** parseText(const char* text, bool verbose) {
	cout << "Text to parse: " << text << endl;

	int next_space_index = 0;
	for (int i = 0; i <= MAX_TEXT_LENGTH; i++) {
		//printf("%c", text[i]); // output for debugging
		if (text[i] == '\0') {

			processSubText(i, &next_space_index);

			printf("Only used %d/%d chars\n", i, MAX_TEXT_LENGTH);
			printf("Highest index of last char: %d\n", i - 1);

			// input consists '\0', stop the remaining (MAX_TEXT_LENGTH - next_space_index) being parsed
			break; 
		}
		else if (text[i] == ' ') {
			
			processSubText(i, &next_space_index);

		}
		else {
			// remove after debugging is done
			//printf("%c\n", text[i]);
		}

	}

	return NULL;
}

void processSubText(int end_of_subtext, int* next_space_index, bool verbose) {
	//split text, actually just access the chars, strcat + strcpy_s into sub_strings
	char* sub_text = (char*)malloc(end_of_subtext - *next_space_index + 1);
	for (int letter = 0; letter < end_of_subtext - *next_space_index; letter++) {
		*(sub_text + letter) = text[*next_space_index + letter];
	}
	*(sub_text + (end_of_subtext - *next_space_index)) = '\0';

	printf("Subtext: %s\n", sub_text);
	free(sub_text);

	*next_space_index = end_of_subtext; // to get to next word, don't +1 !
}