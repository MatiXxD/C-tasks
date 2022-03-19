#include <stdio.h>
#include <limits.h>
#include <math.h>

int main() {

	int day, id, count;
	double sum1, sum2, sum3, sum4, sum5;
	sum1 = sum2 = sum3 = sum4 = sum5 = 0;

	for (day = 1 ; day <= 7 ; day++) {

		printf("Input id of product with amount sold per %d day (-1 in id or count to stop)\n", day);
		scanf_s("%d%d", &id, &count);

		while (id != -1 && count != -1) {

			switch (id) {

				case 1:
					sum1 += count * 2.98;
					break;
				
				case 2:
					sum2 += count * 4.5;
					break;
				
				case 3:
					sum3 += count * 9.98;
					break;

				case 4:
					sum4 += count * 4.49;
					break;

				case 5:
					sum5 += count * 6.87;
					break;

				default:
					puts("You entered the wrong id! Please retry (id from 1 to 5)");
					break;

			}

			scanf_s("%d%d", &id, &count);

		}

	}

	printf("For week total sum of 1 id is %.2f\n", sum1);
	printf("For week total sum of 2 id is %.2f\n", sum2);
	printf("For week total sum of 3 id is %.2f\n", sum3);
	printf("For week total sum of 4 id is %.2f\n", sum4);
	printf("For week total sum of 5 id is %.2f\n", sum5);
	printf("For week total sum is %f\n", sum1 + sum2 + sum3 + sum4 + sum5);
		

	return 0;

}