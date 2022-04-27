#include <stdio.h>
#include <string.h>

int main(void) {

	const unsigned SIZE = 21;
	char firstName[SIZE] = "";
	char lastName[SIZE] = "";

	printf("Enter your firstname: ");
	scanf_s("%s", firstName, SIZE - 1);
	printf("Enter your lastname: ");
	scanf_s("%s", lastName, SIZE - 1);

	printf("%s %s\n%*zu%*zu", firstName, lastName, (unsigned)strlen(firstName),
		strlen(firstName), (unsigned)strlen(lastName) + 1, strlen(lastName));
	puts("\n");
	printf("%s %s\n%-*zu%-*zu", firstName, lastName, (unsigned)strlen(firstName) + 1,
		strlen(firstName), (unsigned)strlen(lastName), strlen(lastName));

    return 0;

}
