#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

char encode(int k, char ch);

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Provide a parameter!\n");
        return 1;
    }

    int k = atoi(argv[1]);

    if (k < 0)
    {
        printf("Parameter should be >= 0!\n");
        return 1;
    }

    // printf("Text: ");
    string plain = GetString();
    
    for (int i = 0; i < strlen(plain); i++)
    {
        printf("%c", encode(k, plain[i]));
    }
    printf("\n");
    return 0;
}

char encode(int k, char ch)
{
    if (!isalpha(ch))
        return ch;

    int length = 'z' - 'a' + 1;
    
    char base = 'A';
    if (islower(ch))
    {
        base = 'a';
    }

    return (char) ((ch - base + k) % length + base);
}
