#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void tower(int n, int i, int j);

int main(void) {

	int n, i, j;

	puts("Enter nember of disks.");
	scanf_s("%d", &n);
	puts("Enter i (from where) and j (where).");
	scanf_s("%d%d", &i, &j);

	tower(n, i, j);

	return 0;

}

void tower(int n, int i, int j) {

	if (n == 1)
		printf("1 disk move from %d to %d\n", i, j);

	else {

		int temp = 6 - i - j;

		tower(n - 1, i, temp);
		printf("%d disk move from %d to %d\n", n, i, j);
		tower(n - 1, temp, j);

	}

}