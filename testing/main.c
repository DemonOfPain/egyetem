#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 4, b = 8;
    while (b != 0) {    /* Euklid�sz */
        int t = b;
        b = a%b;
        a = t;
    }
    return 0;
}
