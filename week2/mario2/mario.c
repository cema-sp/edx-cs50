#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int maxHeight = 23;
    int topWidth = 1;
    int gapSize = 2;
    int height;
    int width;

    do
    {
        printf("height: ");
        height = GetInt();
    } while (height < 0 || height > maxHeight);
    
    width = height + topWidth - 1;

    for (int i = topWidth; i <= width; i++)
    {
        for (int j = 0; j < width - i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        for (int l = 0; l < gapSize; l++)
        {
            printf(" ");
        }
        for (int m = i; m > 0; m--)
        {
            printf("#");
        }
        printf("\n");
    }
}

