#include <stdio.h>
#include <ctype.h>

int get_first(void);

int main(void) {

	printf("Start your input:\n");
	printf("First non space character is %c", get_first());

	return 0;

}

int get_first(void){

	int ch;

	ch = getchar();
	while (isspace(ch))
		ch = getchar();

	return ch;

}
