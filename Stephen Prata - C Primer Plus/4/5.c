#include <stdio.h>

int main(void) {

	float speed, fileSize;

	puts("Enter file's size(Mbyte) and speed(Mbit/s):");
	scanf_s("%f %f", &fileSize, &speed);

	printf("%.2f time to download file (size %.2f Mbyte) with speed %.2f (Mbit/s)\n",
		(fileSize * 8.f) / (speed), fileSize, speed);

    return 0;

}
