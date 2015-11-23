#include <stdio.h>
#include <string.h>
#include <cs50.h>

char upperChar(char ch);

int main(int argc, string argv[])
{
    // printf("Enter your name: ");
    string fullName = GetString();

    int length = strlen(fullName);
    bool isInit = true;

    for (int i = 0; i < length; i++)
    {
        if (fullName[i] != ' ')
        {
            if (isInit)
            {
                printf("%c", upperChar(fullName[i]));
                isInit = false;
            }
        }
        else
        {
            isInit = true;
        }
    }
    printf("\n");
}

char upperChar(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return (char) (ch - 'a' + 'A');
    }
    else
    {
        return ch;
    }
}

