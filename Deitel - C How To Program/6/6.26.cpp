#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8

void printBoard(const int board[][BOARD_SIZE]);
void placeOnBoard(int board[][BOARD_SIZE], int checkBoard[][BOARD_SIZE]);
bool checkPlace(int checkBoard[][BOARD_SIZE], int i, int j);

int main(void) {

	int i;
	int board[BOARD_SIZE][BOARD_SIZE] = { {0} };
	int checkBoard[BOARD_SIZE][BOARD_SIZE] = { {0} };
		 
	srand((int)time(NULL));

	for (i = 1; i <= 8; i++) 
		placeOnBoard(board, checkBoard);

	printBoard(board);
	puts("\n\n\n");
	printBoard(checkBoard);

	return 0;

}

void printBoard(const int board[][BOARD_SIZE]) {

	int i, j;

	for (i = 0; i < BOARD_SIZE; i++) {

		for (j = 0; j < BOARD_SIZE; j++)
			printf("%3d", board[i][j]);

		puts("");

	}

}

void placeOnBoard(int board[][BOARD_SIZE], int checkBoard[][BOARD_SIZE]) {

	static int count = 1;
	int i, j;
	bool stop = false;
	
	for (i = 0; i < BOARD_SIZE; i++) {

		for (j = 0; j < BOARD_SIZE; j++) 
			if (checkPlace(checkBoard, i, j)) {

				board[i][j] = count++;
				stop = true;
				break;

			}

		if (stop)
			break;

	}

}

bool checkPlace(int checkBoard[][BOARD_SIZE], int i, int j) {

	int row = 0;
	int cols = 0;

	if (checkBoard[i][j] == 0) {

		{

			int temp = BOARD_SIZE - 1 - row;

			while (temp + 1) {

				checkBoard[temp][j] = 1;
				temp--;

			}

			while (row < i) {

				checkBoard[row][j] = 1;
				row++;

			}

		}																		//ДЛЯ РЕЗЕРВИРОВАНИЯ ЗНАЧЕНИЙ В СТОЛБЦЕ

		{
			
			int temp = BOARD_SIZE - 1 - cols;

			while (temp + 1) {

				checkBoard[i][temp] = 1;
				temp--;

			}

			while (cols < j) {

				checkBoard[i][temp] = 1;
				cols++;

			}

		}																//ДЛЯ РЕЗЕРВИРОВАНИЯ ЗНАЧЕНИЙ В СТРОКЕ

		{
			int a, b;

			int temp1 = i;
			int temp2 = j;

			for (a = 1; a <= BOARD_SIZE; a++) {

				if (!checkBoard[temp1 % 8][temp2 % 8] && temp1 >= 0 && temp2 >= 0)
					checkBoard[temp1 % 8][temp2 % 8] = 1;

				temp1++;
				temp2--;

			}


			temp1 = i - 1;
			temp2 = j + 1;

			for (a = 1; a <= BOARD_SIZE; a++) {

				if (!checkBoard[temp1 % 8][temp2 % 8] && temp1 >= 0 && temp2 >= 0)
					checkBoard[temp1 % 8][temp2 % 8] = 1;

				temp1--;
				temp2++;

			}
		
		}														//ДЛЯ РЕЗЕРВИРОВАНИЯ ЗНАЧЕНИЙ ДЛЯ ПОБОЧНОЙ ДИАГОНАЛИ

		{
			int a, b;

			int temp1 = i;
			int temp2 = j;

			for (a = 1; a <= BOARD_SIZE; a++) {

				if (!checkBoard[temp1 % 8][temp2 % 8] && temp1 >= 0 && temp2 >= 0)
					checkBoard[temp1 % 8][temp2 % 8] = 1;

				temp1++;
				temp2++;

			}


			temp1 = i - 1;
			temp2 = j + 1;

			for (a = 1; a <= BOARD_SIZE; a++) {

				if (!checkBoard[temp1 % 8][temp2 % 8] && temp1 >= 0 && temp2 >= 0)
					checkBoard[temp1 % 8][temp2 % 8] = 1;

				temp1--;
				temp2--;

			}

		}														//ДЛЯ РЕЗЕРВИРОВАНИЯ ЗНАЧЕНИЙ ДЛЯ ГЛАВНОЙ ДИАГОНАЛИ

		return true;

	}

	else
		return false;
}