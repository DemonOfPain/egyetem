#include <stdio.h>

int main()
{
    int n = 1;
    int szorzat = 1;

    for(int i = 1; i <= 8; i++){
        printf("%d, %d\n", i, szorzat);

        szorzat *= i;
        n++;
    }

    printf("A szorzat = %d", szorzat);
}
