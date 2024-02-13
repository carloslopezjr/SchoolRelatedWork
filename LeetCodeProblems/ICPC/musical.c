#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{

    int cdlen = scanf("%d", &cdlen);
    int n = scanf("%d", &n);

    int num[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d", num[i]);
    }

    int cd1, cd2 = 0;

    for (int j = 0; j < n; j++)
    {

        if (cd1 > cd2)
        {

            cd2 += num[j];
        }
        else
        {

            cd1 += num[j];
        }

        if (cd1 > cdlen)
        {
            cd1 -= num[j];
        }
        else if (cd2 > cdlen)
        {
            cd2 -= num[j];
        }
    }

    if (cd1 > cd2)
    {
        printf("%d %d", cd1, cd2);
    }
    else
    {
        printf("%d %d", cd2, cd1);
    }

    return 0;
}