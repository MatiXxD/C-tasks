#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define BITS_SIZE CHAR_BIT * sizeof(int)


bool isCorrect(const char* bytes);
int binStrToNum(const char* bytes);
void printBytes(int num);


int main(int argc, char* argv[]) {

	int num1, num2;
	char byteStr[BITS_SIZE + 1];

	if (argc > 2 && isCorrect(argv[1]) && isCorrect(argv[2])) {

		num1 = binStrToNum(argv[1]);
		num2 = binStrToNum(argv[2]);

		puts("~num1");
		printBytes(~num1);
		puts("~num2");
		printBytes(~num2);
		puts("num1 & num2");
		printBytes(num1 & num2);
		puts("num1 | num2");
		printBytes(num1 | num2);
		puts("num1 ^ num2");
		printBytes(num1 ^ num2);

	}
	else puts("Error occurred.");

}


bool isCorrect(const char* bytes) {

	while (*bytes) {
		if (*bytes != '0' && *bytes != '1')
			return false;
		bytes++;
	}

	return true;

}

int binStrToNum(const char* bytes) {

	int num = 0x0;
	unsigned int byte = 0x1;

	for (int i = strlen(bytes) - 1; i >= 0; i--) {
		if (bytes[i] == '1')
			num |= byte;
		byte <<= 1;
	}

	return num;

}

void printBytes(int num) {

	unsigned int mask = 0x1 << BITS_SIZE -1;

	for (int i = 0; i < BITS_SIZE; mask >>= 1) {
		printf("%c", num & mask ? '1' : '0');
		if (++i % 8 == 0) putchar(' ');
	}

	putchar('\n');

}
