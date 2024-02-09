// problem for 2.27
#include <stdio.h>

int uadd_ok(unsigned x, unsigned y);

int uadd_ok(unsigned x, unsigned y)
{

    unsigned sum = x + y;
    if (sum >= x) {

        return 1; // no overflow

    } else {

        return 0; // overflow was caused
    }

}

int main() {

    printf("%d\n", uadd_ok(12, 9));

    return 0;
}