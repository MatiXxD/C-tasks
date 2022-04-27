#include <stdio.h>


int main(void) {

	char firstname[20];
	char lastname[20];

	printf("Enter your firstname: ");
	scanf_s("%s", firstname, 20);
	printf("Enter your lastname: ");
	scanf_s("%s", lastname, 20);

	printf("%s, %s.", lastname, firstname);

    return 0;

}
