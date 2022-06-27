#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define SIZE 6

double aton(const char* str);
long atoi(const char* str);

int main(void) {

	// Test aton()
	double num;
	const char* testNums[SIZE] = {
		"42",
		"3.14159",
		"31337 with words",
		"words and 2",
		"-012345",
		"10000000000" };

	for (int i = 0; i < SIZE; i++) {
		if ((num = aton(testNums[i])))
			printf("Number is %.2lf", num);
		else
			printf("\"%s\" isn't a number.", testNums[i]);
		putchar('\n');
	}

	puts("\n\n\n\n");
	// Test atoi()
	long numInt;
	const char* testNumsInt[SIZE] = {
		"42",
		"3414",
		"31337 with words",
		"words and 2",
		"-012345",
		"10000000" };

	for (int i = 0; i < SIZE; i++) {
		if ((numInt = atoi(testNumsInt[i])))
			printf("Number is %d", numInt);
		else
			printf("\"%s\" isn't a number.", testNumsInt[i]);
		putchar('\n');
	}

	return 0;

}

double aton(const char* str) {																									// Simple way using sscanf

	double num;
	int readCount = sscanf_s(str, "%lf", &num);

	if (readCount)
		return num;
	else
		return 0;

}

long atoi(const char* str) {

	bool neg = (str[0] == '-') ? 1 : 0;
	int ind;
	long mlt = 1;
	long num = 0;

	if (neg) ind = 1;																															// If negative number don't check '-' at the start
	else ind = 0;
	for (int i = strlen(str) - 1; i >= ind; i--) {
		if (isdigit(str[i])) {
			if (neg) num -= mlt * (str[i] - 48);
			else num += mlt * (str[i] - 48);
			mlt *= 10;
		}
		else
			return 0;
	}

	return num;

}
