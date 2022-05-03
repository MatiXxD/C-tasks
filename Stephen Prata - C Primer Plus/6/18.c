#include <stdio.h>

int main(void) {

	const int numDunbar = 150;
	int friendsCount = 5;
	int week = 1;

	printf("%10s%10s\n", "Week", "Friends");
	while (friendsCount < numDunbar) {

		friendsCount = (friendsCount - week) * 2;
		printf("%10d%10d\n", week, friendsCount);
		week++;

	}

	return 0;

}
