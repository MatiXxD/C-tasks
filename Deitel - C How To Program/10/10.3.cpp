#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct part {

	int partNumber;
	char partName[25];

}Part;

int main() {

	Part a, b[10], *ptr;
	scanf_s("%d %s", &a.partNumber, a.partName, 10);
	b[3] = a;
	ptr = &b[0];
	printf("%d %s\n", (ptr + 3)->partNumber, (ptr + 3)->partName);

	return 0;

}