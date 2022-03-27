#include <stdio.h>
#include <math.h>

#define RIGHT 0
#define LEFT 1
#define FLOOR_SIZE 50

int xpos = 25;
int ypos = 25;
int FLOOR[FLOOR_SIZE][FLOOR_SIZE] = { 0 };
int direction = 0;
bool pen = false;

int chooseTasks(void);
void normilize(int num);
void move(int steps);
void printArray(void);

int main() {

	bool cont = 1;

	while (cont) {

		cont = chooseTasks();
		puts("\n\n");

	}

	return 0;

}

int chooseTasks(void) {

	int action;
	int cont = 1;
	int	steps = -228;

	printf("Enter what to do:\n1)Pen UP\n2)Pen DOWN\n3)Turn RIGHT\n4)Turn LEFT\n5)5, x Move forward on x steps\n"
		"6)Print array\n9)End\n");

	scanf_s("%d", &action);

	switch (action) {

	case 1:
		pen = false;														// UP
		puts("Pen was uped");
		break;

	case 2:
		pen = true;															// DOWN
		puts("Pen was downed");
		break;

	case 3:
		direction -= 90;
		normilize(direction);
		puts("Turned RIGHT");
		printf("Direction is %u\n", direction);
		break;

	case 4:
		direction += 90;
		normilize(direction);
		puts("Turned LEFT");
		printf("Direction is %u\n", direction);
		break;

	case 5:
		puts("Enter amount of steps to go:");
		while (steps < 0 || steps > 2500)
			scanf_s("%d", &steps);
		move(steps);
		break;

	case 6:
		printArray();
		break;

	case 9:
		cont = 0;
		printArray();
		break;

	default:
		puts("Entered wrong case");
		break;

	}

	return cont;

}

void normilize(int num) {

	int result = num % 360;

	if (result < 0)
		result = 360 - (int)abs(result);

	direction = result;

}

void move(int steps) {

	int addX, addY;
	int i = ypos;
	int j = xpos;
	addX = addY = 0;

	switch (direction) {

	case 0:
		addX = 1;
		addY = 0;
		break;

	case 90:
		addX = 0;
		addY = -1;
		break;

	case 180:
		addX = -1;
		addY = 0;
		break;

	case 270:
		addX = 0;
		addY = 1;
		break;

	}

	if (pen == true)
		while (steps) {

			FLOOR[i][j] = 1;
			i += addY;
			j += addX;

			if (j == 50 && addX == -1) {

				i -= 1;
				j = 0;

			}

			else if (j == 50 && addX == 1) {

				i += 1;
				j = 0;

			}

			if (i == 50)
				i = 0;


			steps--;

		}

	else
		while (steps) {

			i += addY;
			j += addX;

			steps--;

		}

	xpos = j;
	ypos = i;

}

void printArray(void) {

	int i, j;

	for (i = 1; i < FLOOR_SIZE; i++) {

		for (j = 1; j < FLOOR_SIZE; j++)
			printf("%c", (FLOOR[i][j] == 1) ? '#' : '.');

		puts("");

	}

}