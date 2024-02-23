#include <stdio.h>

int main()
{
    char string[100];
    int repeat;

    scanf("%s", string);
    scanf("%d", &repeat);

    for (int i = 0; i < repeat; i++)
    {
        printf("%s ", string);
    }

    return 0;
}