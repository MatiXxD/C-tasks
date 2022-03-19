#include <stdio.h>
#include <limits.h>
#include <math.h>

int main() {

    int amount;
    int addAmount, addPrincipal;
    int save;
    int principal = 1000; 
    int rate = 5; 
    unsigned int year; 

    printf("%4s%21s\n", "Year", "Amount on deposit");

    for (year = 1; year <= 10; ++year) {                                                                    //ТОП МУВЫ

        amount = principal * pow((100.0 + rate) / 100, year);
        save = (principal * pow((100.0 + rate) / 100, year) - amount) * 10000000;
        
        if (save % 100000 > 50000)
            addAmount = save / 100000 + 1;
        else
            addAmount = save / 100000;

        if ((addAmount != 0 && addAmount < 10) || addAmount == 0)
            printf("%4u%18d.%d%d\n", year, amount, 0, addAmount);
        else
            printf("%4u%18d.%2d\n", year, amount, addAmount);
    } 

	return 0;

}