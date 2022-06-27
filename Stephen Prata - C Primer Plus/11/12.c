#include <stdio.h>
#include <ctype.h>

#define SIZE 1024

void readStr(char* str, int size);
void parseStr(char* str);

int main(void) {

	char str[SIZE];

	puts("Start input (EOF to stop):");
	readStr(str, SIZE);

	parseStr(str);

	return 0;

}

void readStr(char* str, int size) {

	int i = 0;
	char ch;

	while ((ch = getchar()) != EOF && i < size - 1)
		str[i++] = ch;
	str[i] = '\0';

}

void parseStr(char* str) {

	int inword = 0;
	char prvVal = ' ';
	unsigned wordsCount, numsCount, upperCount, lowerCount, punctCount;
	wordsCount = numsCount = upperCount = lowerCount = punctCount = 0;

	while (*str) {
		if (isdigit(*str)) {
			numsCount++;
			inword = 1;
		}
		else if (islower(*str)) {
			lowerCount++;
			inword = 1;
		}
		else if (isupper(*str)) {
			upperCount++;
			inword = 1;
		}
		else if (ispunct(*str)) {
			punctCount++;
			inword = 1;
		}
		else if (isspace(*str) && inword) {
			wordsCount++;
			inword = 0;
		};

		prvVal = *str;
		str++;
	}

	puts("Your input contains: ");
	printf("%d words\n%d nums\n%d lowercase\n%d uppercase\n%d punct\n",
		wordsCount, numsCount, lowerCount, upperCount, punctCount);

}
