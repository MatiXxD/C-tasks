#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


typedef struct {
	unsigned int fontIdent		: 8;
	unsigned int fontSize		: 7;
	unsigned int alignment		: 2;
	bool isBold					: 1;
	bool isItalics				: 1;
	bool isUnderlined			: 1;
}fontProp;


void cleanLine(void);
char getOption(void);
void printProp(const fontProp* text);
void setProp(fontProp* text, char option);


int main(void) {

	char option;
	fontProp text = {1, 12, 0, 0, 0, 0};

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

void printProp(const fontProp* text) {

	static const char* alignmentVal[3] = { "left", "center", "right" };
	static const char* onOrOff[2] = { "OFF", "ON" };

	printf("%3s%5s%10s%5s%5s%5s\n", "ID", "Size",
		"Alignment", "B", "I", "U");
	printf("%3d%5d%10s%5s%5s%5s\n\n", text->fontIdent, text->fontSize,
		alignmentVal[text->alignment], onOrOff[text->isBold],
		onOrOff[text->isItalics], onOrOff[text->isUnderlined]);

}

void setProp(fontProp* text, char option) {

	unsigned num;

	switch (option) {
	case 'f': {
		printf("Enter font ID (0-255): ");
		if (scanf("%d", &num) != 1) exit(EXIT_FAILURE);
		else text->fontIdent = num;
		cleanLine();
		break;
	}
	case 's': {
		printf("Enter font ID (0-127): ");
		if (scanf("%d", &num) != 1) exit(EXIT_FAILURE);
		else text->fontSize = num;
		cleanLine();
		break;
	}
	case 'a': {
		printf("Enter alignment (left, center, right): ");
		if (getchar() == 'l')		text->alignment = 0;
		else if (getchar() == 'e')	text->alignment = 1;
		else						text->alignment = 2;
		cleanLine();
		break;
	}
	case 'b': {
		text->isBold ^= 0x1;
		break;
	}
	case 'i': {
		text->isItalics ^= 0x1;
		break;
	}
	case 'u': {
		text->isUnderlined ^= 0x1;
		break;
	}
	}

}
