#include <iostream>

int main() {

	// C-style
	char text[10] = ""; // this will get whole line, but won't work with strstr
	//char* text_2 = NULL; // maybe malloc this, might make things easier :)
	char* sub_strings[] = { NULL };

	printf("Type something: ");
	gets_s(text); // C: gets
	//printf("%s\n", text);

	int first_space = 0;
	for (int i = 0; i <= 10; i++) {
		if (text[i] == '\0') {
			printf("Only used %d/10 chars\n", i);
			printf("Highest index of last char: %d\n", i - 1);
			break;
		}
		else if (text[i] == ' ') {
			// for now, this will end up with the position of last space
			printf("\n");
			first_space = i;
			continue; // skip the space

		}
		else {
			printf("%c\n", text[i]);
		}
		
	}
	printf("Position of 1st occuring space: %d\n", first_space);

	// concept for sub texts
	char balloon[10] = "red";
	balloon[3] = '\0';
	balloon[4] = 'q';
	printf("%s\n", balloon);
	
	char* new_balloon = (char*) malloc(strlen(balloon) + 1);

	if (new_balloon != NULL) { printf("Successfully malloc for new_balloon\n"); }
	strcpy_s(new_balloon, 4, balloon); // stupid C++ :)
	printf("Size of balloon: %d\n", strlen(balloon));
	printf("Size of new balloon: %d\n", strlen(new_balloon));

	printf("First char of new_balloon: %c\n", *new_balloon);
	// same as *(new_balloon++), but not same as (*new_balloon)++, ascii (r+1) => s
	printf("Second char of new_balloon: %c\n", *(new_balloon + 1));
	printf("Third char of new_balloon: %c\n", *(new_balloon + 2));
	printf("Fourth char of new_balloon: %c\n", *(new_balloon + 3)); // null, empty output

	printf("new_balloon: %s", new_balloon);

	free(new_balloon);

	// refer to:
	// "Understanding and Using C Pointers" book (p. 101, Chinese version)
	/*
	char* new_text =  (char*) malloc(sizeof(char*) * 10);
	strcpy(new_text, text);
	while (*new_text) {
		printf("%c", *new_text);
		new_text++;
	}
	free(new_text);
	*/
	

	

	return 0;
}