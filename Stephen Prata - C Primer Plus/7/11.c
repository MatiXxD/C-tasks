#include <stdio.h>

const float PRICE1 = 2.05;
const float PRICE2 = 1.15;
const float PRICE3 = 1.09;

float getPriceForDelivery(float totalWeight);

int main(void) {

	float artichokeWeight, beetWeight, carrotWeight, weight;
	artichokeWeight = beetWeight = carrotWeight = 0;
	char option;

	printf("Start your input:\n1) a for artichoke\n"
		"2) b for beet\n3) c for carrot\n4) for exit\n\n");
	printf("Enter option (a, b, c, q): ");
	while ((option = getchar()) != 'q') {

		printf("Enter weight: ");
		scanf_s("%f", &weight);

		switch (option) {

		case 'a':
			artichokeWeight += weight;
			break;
		case 'b':
			beetWeight += weight;
			break;
		case 'c':
			carrotWeight += weight;
			break;

		}
		getchar();

		printf("Enter option (a, b, c, q): ");

	}

	printf("\nYour order is (weight):\n");
	printf("%20s%20s%20s\n", "Artichoke", "Beet", "Carrot");
	printf("%20.2f%20.2f%20.2f\n\n", artichokeWeight, beetWeight, carrotWeight);


	float priceA = artichokeWeight * PRICE1;
	float priceB = beetWeight * PRICE2;
	float priceC = carrotWeight * PRICE3;

	printf("\nYour order is (price):\n");
	printf("%20s%20s%20s\n", "Artichoke", "Beet", "Carrot");
	printf("%20.2f%20.2f%20.2f\n\n", priceA, priceB, priceC);


	float totalSum = priceA + priceB + priceC;
	float delivery = getPriceForDelivery(artichokeWeight + beetWeight + carrotWeight);

	printf("Total sum is %.2f\n", totalSum);
	if ((int)totalSum > 100) {
		totalSum = totalSum - totalSum * 0.05;
		printf("You get discount. Now your total sum is %.2f\n", totalSum);
	}
	printf("Cost for delivery is %.2f\n", delivery);
	printf("Your order is %.2f\n", totalSum + delivery);

	return 0;

}

float getPriceForDelivery(float totalWeight) {

	if (totalWeight <= 5)
		return 6.5;
	else if (totalWeight <= 20)
		return 14.0;
	else
		return 14.0 + (totalWeight - 14.0) * 0.5;

}
