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
    unsigned x = 10; // uni max which is the max limit for the bit size - 1
    unsigned y = 2; 

    printf("Test Cases\n\nx = %d\ny = %d\n\nOutput: ", x, y);

    printf("%d\n", uadd_ok(x, y));

    return 0;
}