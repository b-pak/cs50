#include <cs50.h>
#include <stdio.h>
#include <math.h>

// This program computes the smallest number of coins needed to return change owed

int main(void)
{
    float dollars = get_float("Change owed: ");
    while (dollars <= 0)
    {
        printf("Change owed: foo\n");
        dollars = get_float("Change owed: ");
    }
    int cents = round(dollars * 100);
    int count = 0;
    while (cents >= 25)
    {
        count++;
        cents = cents - 25;
    }
    while (cents >= 10)
    {
        count++;
        cents = cents - 10;
    }
    while (cents >= 5)
    {
        count++;
        cents = cents - 5;
    }
    while (cents >= 1)
    {
        count++;
        cents = cents - 1;
    }
    printf("%d\n", count);
}
