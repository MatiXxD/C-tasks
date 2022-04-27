#include <stdio.h>
#include <string.h>

int main(void) {

	char name[20] = "";

	printf("Enter name: ");
	scanf_s("%s", name, 20);

	printf("\"%s\"\n", name);
	printf("\"%20s\"\n", name);
	printf("\"%-20s\"\n", name);
	printf("\"%*s\"\n", (unsigned)strlen(name) + 3, name);

    return 0;

}
