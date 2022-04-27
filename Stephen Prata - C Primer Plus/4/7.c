#include <stdio.h>
#include <float.h>

int main(void) {

	double numDouble = 1.0 / 3.0;
	float numFloat = 1.0f / 3.0f;

	printf("FLT_DIG = %d\n", FLT_DIG);
	printf("DBL_DIG = %d\n\n", DBL_DIG);

	printf("1)%20.4f%20.4lf\n", numFloat, numDouble);		//YES
	printf("2)%20.12f%20.12lf\n", numFloat, numDouble);		//NO
	printf("3)%20.16f%20.16lf\n", numFloat, numDouble);		//NO

    return 0;

}
