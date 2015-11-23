#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int calculateCS(long long cardNumber, int length);
void checkCSFor(int checkSum, string name);

int main(void)
{
    int maxLength = 16;
    int minLength = 13;
 
    printf("Number: ");
    long long cardNumber = GetLongLong();
    
    int length = maxLength;
    long long divider = (long long) pow(10, length - 1);
    int headDigit = 0;
    long long tailDigits = cardNumber;
    
    // Find length of card number
    for(length = maxLength; length >= minLength && headDigit == 0; length--)
    {
        headDigit = (int) (tailDigits / divider);
        tailDigits = tailDigits % divider;
        divider /= 10;
    }

    // Compensate -- on last iteration
    length++;
    
    if (headDigit == 3 && length == 15)
    {
        // Maybe AMEX
        checkCSFor(calculateCS(cardNumber, length), "AMEX");
    }
    else if (headDigit == 4 && (length == 13 || length == 16))
    {
        // Maybe VISA
        checkCSFor(calculateCS(cardNumber, length), "VISA");
    }
    else if (headDigit == 5 && length == 16)
    {
        // Maybe MASTERCARD
        int secondDigit = (int) (tailDigits / divider);
        if (secondDigit != 1 && 
          secondDigit != 2 && 
          secondDigit != 3 && 
          secondDigit != 4 && 
          secondDigit != 5)
        {
            printf("INVALID\n");
        }
        else
        {
            checkCSFor(calculateCS(cardNumber, length), "MASTERCARD");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int calculateCS(long long cardNumber, int length)
{
    long long initDigits = cardNumber;
    int lastDigit = 0;

    bool isEven = false;
    int checkSum = 0;
    do
    {
        lastDigit = (int) (initDigits % 10);
        initDigits /= 10;

        if (isEven == true)
        {
            int doubled = lastDigit * 2;
            if (doubled / 10 > 0)
            {
                checkSum += doubled / 10 + doubled % 10;
            }
            else
            {
                checkSum += doubled;
            }
            isEven = false;
        }
        else
        {
            checkSum += lastDigit;
            isEven = true;
        }
    } while (initDigits != 0);
    
    return checkSum;
}

void checkCSFor(int checkSum, string name)
{    
    if (checkSum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        printf("%s\n", name);
    }
}

