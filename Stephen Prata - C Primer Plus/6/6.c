#include <stdio.h>


int main(void) {

	unsigned top, bot;

	printf("Enter bot and top numbers(should be positive): ");
	scanf_s("%u%u", &bot, &top);

	printf("%8s%8s%8s\n", "Num", "Square", "Cube");
	for (int num = bot; num <= top; num++)
		printf("%8u%8u%8u\n", num, num * num, num * num * num);

	return 0;

}
