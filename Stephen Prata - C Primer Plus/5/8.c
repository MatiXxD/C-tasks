#include <stdio.h>


int main(void) {

	long op1, op2;

	printf("Enter second operand for \"%%\" (op1 %% op2<-this): ");
	scanf_s("%d", &op2);
	printf("Enter first operand for \"%%\" (this->op1 %% op2): ");
	scanf_s("%d", &op1);

	while (op1 > 0) {

		printf("%d %% %d = %d\n", op1, op2, op1 % op2);

		printf("Enter first operand for \"%%\" (this->op1 %% op2): ");
		scanf_s("%d", &op1);

	}

	return 0;

}
