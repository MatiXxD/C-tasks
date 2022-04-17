#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


long product(int n, ...);


int main(void) {

    int x = 5;
    int y = 3;
    int z = 11;
    int t = 8;

    printf("%d*%d = %ld\n", x, y, product(2, x, y));
    printf("%d*%d*%d = %ld\n", x, y, z, product(3, x, y, z));
    printf("%d*%d*%d*%d = %ld\n", x, y, z, t, product(4, x, y, z, t));

    return 0;
}


long product(int n, ...) {

    long total = 1;
    va_list nums;
    va_start(nums, n);

    for (int i = 1; i <= n; i++)
        total *= va_arg(nums, int);

    va_end(nums);

    return total;

}