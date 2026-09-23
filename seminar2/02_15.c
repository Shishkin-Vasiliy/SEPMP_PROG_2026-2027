#include <stdio.h>

float yearfrac(int year, int day);

int main(void)
{
    printf("%f\n", yearfrac(2019, 300)); 
    printf("%f\n", yearfrac(2019, 100));
    printf("%f\n", yearfrac(2020, 100)); 

    return 0;
}

float yearfrac(int year, int day) 
{
    int days_in_year = 365;

    if (year % 4 == 0) 
        days_in_year = 366;

    return (float)day / days_in_year;
}

