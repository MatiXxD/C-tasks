#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int currentRow = 3; 
int currentColumn = 4;
int moveCount = 1;

int move(int board[][8], int acessBoard[][8]);
int checkMove(int board[][8], int acessBoard[][8], int horizontalMove, int verticalMove, int acess);
void printArray(int board[][8]);

int main(void) {

	int board[8][8] = { {0} };
	int acessBoard[8][8] = { 2, 3, 4, 4, 4, 4, 3, 2,
							3, 4, 6, 6, 6, 6, 4, 3,
							4, 6, 8, 8, 8, 8, 6, 4,
							4, 6, 8, 8, 8, 8, 6, 4,
							4, 6, 8, 8, 8, 8, 6, 4,
							4, 6, 8, 8, 8, 8, 6, 4,
							3, 4, 6, 6, 6, 6, 4, 3,
							2, 3, 4, 4, 4, 4, 3, 2 };
	bool flag = 1;

	board[currentRow][currentColumn] = 1;
	moveCount++;

	while (flag) 
		flag = move(board, acessBoard);

	printf("Moved %d times\n\n", moveCount - 1);
	printArray(board);

	return 0;

}

int move(int board[][8], int acessBoard[][8]) {

	int i, j;
	int stop;
	int acess = 2;

	static const int vertical[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
	static const int horizontal[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

	for (j = 1; j <= 4; j++) {

		for (i = 0; i < 8; i++) {
			stop = checkMove(board, acessBoard, horizontal[i], vertical[i], acess);


			if (stop)
				break;

		}

		acess += 2;
		if (stop)
			break;

	}

	if (i == 8 && stop == 0)
		return 0;

	return 1;

}

int checkMove(int board[][8], int acessBoard[][8], int horizontalMove, int verticalMove, int acess) {

	int	temp1 = currentRow + verticalMove;
	int temp2 = currentColumn + horizontalMove;

	if (temp1 > 7 || temp1 < 0 || temp2 > 7 || temp2 < 0)
		return 0;

	else if (!board[temp1][temp2] && acessBoard[temp1][temp2] == acess) {

		board[temp1][temp2] = moveCount++;
		acessBoard[temp1][temp2] = 0;
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