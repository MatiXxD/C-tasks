#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void) {

	static int count = 1;

	printf("%d\n", count++);
	main();

	return 0;

}