#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main() {


    //1.
    int n = 1;
    int szorzat = 1;
    while(n <= 8) {
        szorzat *= n;
        n++;
    }
    printf("Szorzat erteke %i\n", szorzat);


    /*
    //1.2
    int szorzat = 1;
    int n = 8;
    while (n > 1) {
        szorzat *= n;
        n -= 1;
    }
    printf("%d\n", szorzat);
    */

    /*
    //2.
    int a = 11220;
    int b = 2002;
    while (b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    printf("lnko = %d\n", a);
    */

    /*
    //3.
    char betu;
    while (scanf("%c", &betu) == 1)
        printf("betu='%c', betu=%d\n", betu, betu);

    //4.
    int tomb[10];

    for (int i = 0; i < 10; i += 1)
        tomb[i] = i * 10;

    int i = 0;
    while (true) {
        printf("%d. elem: %d\n", i, tomb[i]);
        i += 1;
    }
    */

    /*
    //5.
    int tomb[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int legkissebb = tomb[0];
    int minhely = 0;

    printf("A tomb:");
    for(int i = 0; i < 10; i++) {
        printf(" [%i]=%i", i, tomb[i]);
        if(tomb[i] < legkissebb) {
            legkissebb = tomb[i];
            minhely = i;
        }
    }
    printf("\nA legkisebb szam: %i", legkissebb);
    printf("\nA legkisebb indexe: %i", minhely);
    */

    /*
    //5.2.
    int tomb[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int legkissebb = tomb[0];
    int minhely;

    for(int i = 0; i < 10; i++) {
        if(tomb[i] < legkissebb) {
            legkissebb = tomb[i];
            minhely = i;
        }
    }

    printf("A tomb:");
    for(int i = 0; i < 10; i++) {
        printf(" %i", tomb[i]);
        if(tomb[i] == legkissebb) {
            printf("[MIN]");
        }
    }

    printf("\nA legkisebb szam: %i", legkissebb);
    printf("\nA legkisebb indexe: %i", minhely);
    */

    /*
    //6.
    char p[10] = {'P', 'i', 't', 'a', 'g', 'o', 'r', 'a', 's', 'z'};

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            char x[10];
            int temp = (j + i) % 10;
            x[j] = p[temp];
            printf("%c ", x[j]);
        }
        printf("\n");
    }
    */

}




