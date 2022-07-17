#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


void cleanLine(void);
char getOption(void);
void printProp(unsigned* text);
void setProp(unsigned* text, char option);


int main(void) {

	char option;

	// Init text
	unsigned int text = 0x0;
	text |= 1;							// size 8
	text |= 12 << 8;					// size 7
	text |= 0 << 15;					// size 2
	text |= 0 << 17;					// size 1
	text |= 0 << 18;					// size 1
	text |= 0 << 19;					// size 1

	printProp(&text);
	while ((option = getOption()) != 'e') {
		setProp(&text, option);
		puts("After changes:");
		printProp(&text);
	}

	return 0;

}


void cleanLine(void) {

	while (getchar() != '\n')
		continue;

}

char getOption(void) {

	char option;
	printf("Enter what you want to do:\n%s %s %s\n%s %s %s %s\n",
		"f) Change font ID", "s) Change font size", "a) Change alignment",
		"b) Bold", "i) Italics", "u) Underlined", "e) Exit");

	option = tolower(getchar());
	cleanLine();
	while (strchr("fsabiue", option) == NULL) {
		printf("Wrong input. Try again: ");
		option = tolower(getchar());
		cleanLine();
	}

	return option;

}

void printProp(unsigned* text) {

	static const char* alignmentVal[7] = { "left", "center", "right" };								// 7 to avoid warnings
	static const char* onOrOff[2] = { "OFF", "ON" };

	// get values
	unsigned int fontIdent = *text & 0xFF;
	unsigned int fontSize = (*text >> 8) & 0x7F;
	unsigned int alignment = (*text >> 15) & 0x3;
	bool isBold = (*text >> 17) & 0x1;
	bool isItalics = (*text >> 18) & 0x1;
	bool isUnderlined = (*text >> 19) & 0x1;


	printf("%3s%5s%10s%5s%5s%5s\n", "ID", "Size",
		"Alignment", "B", "I", "U");
	printf("%3d%5d%10s%5s%5s%5s\n\n", fontIdent, fontSize,
		alignmentVal[alignment], onOrOff[isBold],
		onOrOff[isItalics], onOrOff[isUnderlined]);

}

void setProp(unsigned* text, char option) {

	unsigned num;

	switch (option) {
	case 'f': {
		printf("Enter font ID (0-255): ");

		if (scanf("%d", &num) != 1 || num > 255) {
			puts("Wrong input. Exiting...");
			exit(EXIT_FAILURE);
		}
		else {
			*text &= ~0xFFu;			// clear before change
			*text |= num;
		}

		cleanLine();
		break;
	}
	case 's': {
		printf("Enter font ID (0-127): ");

		if (scanf("%d", &num) != 1 || num > 127) {
			puts("Wrong input. Exiting...");
			exit(EXIT_FAILURE);
		}
		else {
			*text &= ~0x7F00u;			// clear before change
			*text |= num << 8;
		}

		cleanLine();
		break;
	}
	case 'a': {
		printf("Enter alignment (left, center, right): ");

		if (getchar() == 'l')		num = 0;
		else if (getchar() == 'e')	num = 1;
		else						num = 2;

		*text &= ~0x38000u;				// clear before change
		*text |= num << 15;

		cleanLine();
		break;
	}
	case 'b': {
		*text ^= 0x1 << 17;
		break;
	}
	case 'i': {
		*text ^= 0x1 << 18;
		break;
	}
	case 'u': {
		*text ^= 0x1 << 19;
		break;
	}
	}

}
