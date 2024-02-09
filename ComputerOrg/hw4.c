// problem for 2.27
#include <stdio.h>
#include <limits.h>

int uadd_ok(unsigned x, unsigned y);

int uadd_ok(unsigned x, unsigned y)
{

    unsigned sum = x + y;
    if (sum >= x)
    {

        return 1; // no overflow
    }
    else
    {

        return 0; // overflow was caused
    }
}

int main()
{
    unsigned x = UINT_MAX - 1; // uni max which is the max limit for the bit size
    unsigned y = 2; 

    printf("%d\n", uadd_ok(x, y));

    return 0;
}