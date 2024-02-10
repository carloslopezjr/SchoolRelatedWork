#include <stdio.h>
#include <limits.h>

int uadd_ok(unsigned x, unsigned y);
int taad_ok(int x, int y);

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

int tadd_ok(int x, int y)
{
    int sum = x + y;

    if (x < 0 && y < 0 && sum >= 0 || x > 0 && y > 0 && sum <= 0) // conditional test for pos overflow and negative overflow
    {
        return 0;
    }
    else {
        return 1;
    }
// this is a comment
}

int main()
{
    int x = 21; // the max size of an int with a 32 bit system
    int y = 1;

    printf("Test Cases\n\nx = %d\ny = %d\n\nOutput: ", x, y);

    printf("%d\n", tadd_ok(x, y));

    return 0;
}