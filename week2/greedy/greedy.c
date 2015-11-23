#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    
    int coins = 0;

    float change = 0;
    int changePennies = 0;
    do
    {
        printf("How much change is owed?\n");
        change = GetFloat();
    } while (change <= 0);
    
    changePennies = (int)(round(change * 100));
    
    coins += changePennies / quarter;
    changePennies = changePennies % quarter;

    coins += changePennies / dime;
    changePennies = changePennies % dime;

    coins += changePennies / nickel;
    changePennies = changePennies % nickel;

    coins += changePennies / penny;
    changePennies = changePennies % penny;

    printf("%d\n", coins);
}

