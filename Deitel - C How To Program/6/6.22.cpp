#include <stdio.h>
#define SELLERS 5
#define PRODUCTS 6

void fillArray(float sale[][PRODUCTS]);
int inputSellerID(void);
void printArray(float sale[][PRODUCTS]);

int main(void) {

	float sale[SELLERS][PRODUCTS] = { 0 };

	fillArray(sale);
	printArray(sale);


	return 0;

}

void fillArray(float sale[][PRODUCTS]) {

	float sellAmount;
	int sellerID, productID;

	sellerID = inputSellerID();

	while (sellerID != -1) {

		printf("Enter product code: ");
		scanf_s("%d", &productID);
		while (productID != 1 && productID != 2 && productID != 3 && productID != 4 && productID != 5) {

			puts("Enter correct product number!\nFrom 1 to 4.");
			scanf_s("%d", &sellerID);

		}

		printf("Enter sold sum for %d seller, %d product: ", sellerID, productID);
		scanf_s("%f", &sellAmount);

		sale[sellerID][productID] += sellAmount;

		puts("\n\n------------------------------------------------------------------------------------------------------\n\n");

		sellerID = inputSellerID();

	}

}

int inputSellerID(void) {

	int sellerID;

	printf("%s", "Enter sellers number (-1 to stop input): ");
	scanf_s("%d", &sellerID);
	while (sellerID != 1 && sellerID != 2 && sellerID != 3 && sellerID != 4 && sellerID != -1) {

		puts("Enter correct seller number!\nFrom 1 to 4.");
		scanf_s("%d", &sellerID);

	}

	return sellerID;

}

void printArray(float sale[][PRODUCTS]) {

	int i, j;
	float total;
	float arr[PRODUCTS] = { 0 };

	puts("\n------------------------------------------------RESULT------------------------------------------------\n");
	printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%s\n\n", "", 1, 2, 3, 4, 5, "Tot");

	for (i = 1; i < SELLERS; i++) {

		printf("%d", i);
		total = 0;

		for (j = 1; j < PRODUCTS; j++) {

			printf("\t\t%.2f", sale[i][j]);
			total += sale[i][j];
			arr[j] += sale[i][j];

		}

		printf("\t\t%.2f\n", total);

	}

	printf("\n%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t", "Tot", arr[1], arr[2], arr[3], arr[4], arr[5]);

}