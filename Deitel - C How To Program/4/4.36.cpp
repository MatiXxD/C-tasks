#include <stdio.h>
#include <limits.h>
#include <math.h>

int main() {

    int year;
    int start = 0;
    int month;
    int day, days;
    int count;

    puts("Enter year (from 1994 to 1999)");
    scanf_s("%d", &year);

    switch (year) {                                         

    case 1994:
        start = 5;
        break;

    case 1995:
        start = 6;
        break;

    case 1996:
        start = 0;
        break;

    case 1997:
        start = 2;
        break;

    case 1998:
        start = 3;
        break;

    case 1999:
        start = 4;
        break;

    default:
        start = -1;
        break;

    }                                                                                            

    for (month = 1; month <= 12; month++) {
        
        if (start == -1) {

            puts("You have entered the wrong year. Restart programm and chose again FROM 1994 TO 1999");
            break;

        }
            

        switch (month) {
        
        case 1:
            puts("January");
            break;

        case 2:
            puts("February");
            break;

        case 3:
            puts("March");
            break;

        case 4:
            puts("April");
            break;

        case 5:
            puts("May");
            break;

        case 6:
            puts("June");
            break;

        case 7:
            puts("July");
            break;

        case 8:
            puts("August");
            break;

        case 9:
            puts("September");
            break;

        case 10:
            puts("October");
            break;

        case 11:
            puts("November");
            break;

        case 12:
            puts("December");
            break;

        }
        puts("Mon\tTue\tWed\tThu\tFri\tSat\tSun");

        count = start;
        while (start--)
            printf("\t");

        if (month == 1 || month == 3 || month == 5 || month == 7 ||
            month == 8 || month == 10 || month == 12)
            days = 31;

        else if (month == 4 || month == 6 || month == 9 || month == 11)
            days = 30;

        else if (month == 2 && year != 1996)
            days = 28;

        else
            days = 29;

        for (day = 1; day <= days; day++) {
                
            if (!(count % 7) && count != 0)
                puts("");

            printf("%d\t", day);

            count++;
        }
        
        start = count % 7;
        puts("\n\n");

    }


    return 0;

}