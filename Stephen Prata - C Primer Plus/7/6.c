#include <stdio.h>
#include <stdbool.h>

int main(void) {

	int count = 0;
	char ch;
	bool flag = false;

	printf("Start your input:\n");
	while ((ch = getchar()) != '#') {

		if (ch == 'e')
			flag = true;
		if (ch == 'i' && flag) {
			count++;
			flag = false;
		}

	}
	printf("Count = %d\n", count);

	return 0;

}
