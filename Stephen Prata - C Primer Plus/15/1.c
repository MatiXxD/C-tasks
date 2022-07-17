#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define BITS_SIZE CHAR_BIT * sizeof(int)


char* s_gets(char str[], int size);
bool isCorrect(char* bytes);
int binStrToNum(char* bytes);


int main(void) {

	char byteStr[BITS_SIZE + 1];

	printf("Enter binary number: ");
	if (s_gets(byteStr, BITS_SIZE + 1) && isCorrect(byteStr))
		printf("Number is %d\n", binStrToNum(byteStr));
	else
		printf("Error occurred.\n");

}


char* s_gets(char str[], int size) {

	char* retVal = fgets(str, size, stdin);
	if (retVal) {

		while (*str != '\0' && *str != '\n')
			str++;

		if (*str) *str = '\0';
		else
			while (getchar() != '\n') continue;

	}

	return retVal;

}

bool isCorrect(char* bytes) {

	while (*bytes) {
		if (*bytes != '0' && *bytes != '1')
			return false;
		bytes++;
	}

	return true;

}

int binStrToNum(char* bytes) {

	int num = 0x0;
	int byte = 0x1;

	while (*bytes) {
		if (*bytes++ == '1')
			num |= byte;
		byte <<= 1;
	}

	return num;

}
