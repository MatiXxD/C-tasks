#include <stdio.h>

int currentRow = 3; 
int currentColumn = 4;
int moveCount = 1;

int move(int board[][8]);
int checkMove(int board[][8], int horizontalMove, int verticalMove);
void printArray(int board[][8]);

int main(void) {

	int board[8][8] = { {0} };
	bool flag = 1;

	board[currentRow][currentColumn] = 1;
	moveCount++;

	while (flag) 
		flag = move(board);

	printf("Moved %d times\n\n", moveCount - 1);
	printArray(board);

	return 0;

}

int move(int board[][8]) {

	int i;
	int stop;

	static const int vertical[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
	static const int horizontal[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

	for (i = 0; i < 8; i++) {

		stop = checkMove(board, horizontal[i], vertical[i]);

		if (stop)
			break;
		
	}

	if (i == 8 && stop == 0)
		return 0;

	return 1;

}

int checkMove(int board[][8], int horizontalMove, int verticalMove) {

	int	temp1 = currentRow + verticalMove;
	int temp2 = currentColumn + horizontalMove;

	if (temp1 > 7 || temp1 < 0 || temp2 > 7 || temp2 < 0)
		return 0;

	else if (!board[temp1][temp2]) {

		board[temp1][temp2] = moveCount++;
		currentRow = temp1;
		currentColumn = temp2;

		return 1;

	}

	else
		return 0;

}

void printArray(int board[][8]){

	int i, j;

	for (i = 0; i < 8; i++) {

		for (j = 0; j < 8; j++)
			printf("%3d", board[i][j]);

		puts("");

	}

}