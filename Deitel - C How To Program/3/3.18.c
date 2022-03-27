#include <stdio.h>

int main() {
	
	int id;
	float startBalance;
	float credit, creditLimit, expenses;
	float endBalance = -1337;

	printf("%s","Enter the id of the customer(-1 to stop input): ");
	scanf_s("%d", &id);

	while (id != -1) {

		printf("%s", "Enter start balance: ");				// НАЧАЛЬНЫЙ БАЛАНС 
		scanf_s("%f", &startBalance);

		printf("%s", "Enter expenses: ");					// ЗАТРАТЫ
		scanf_s("%f", &expenses);

		printf("%s", "Enter credit: ");						// КРЕДИТ
		scanf_s("%f", &credit);

		printf("%s", "Enter credit limit: ");				// МАКСИМАЛЬНЫЙ РАЗМЕР КРЕДИТА 
		scanf_s("%f", &creditLimit);

		endBalance = startBalance + expenses - credit;		// РАСЧЁТ НОВОГО БАЛАНСА

		puts("\n\t\tMAIN INFO");
		printf("The id of the customer: %d\n", id);			// ВЫВОД ОСНОВНОЙ ИНФОРМАЦИИ 
		printf("Credit limit: %.2f\n", creditLimit);
		printf("Balance: %.2f\n", endBalance);

															
		if (endBalance > creditLimit)						// ПРОВЕРКА НА ПРЕВЫШЕНИЕ ЛИМИТА
			puts("Credit limit was exceeded");
		puts("\n\n--------------------------------------------------------------------------\n\n");

		printf("%s", "Enter the id of the customer(-1 to stop input): ");		// ВВОД СЛЕД. ID
		scanf_s("%d", &id);
	}

	if (endBalance == -1337)
		puts("Nothing was entered\n");

	return 0;
}