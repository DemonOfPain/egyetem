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
    printf("Szorzat erteke %d\n", szorzat);


    //1.2
    int szorzat2 = 1;
    int n2 = 8;
    while (n2 > 1) {
        szorzat2 *= n2;
        n2 -= 1;
    }
    printf("%d\n", szorzat2);


    //2.
    int a = 11220;
    int b = 2002;
    while (b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    printf("lnko = %d\n", a);


    //3.
    char betu;
    while (scanf("%c", &betu) == 1)
        printf("betu='%c', betu=%d\n", betu, betu);


    //4.
    int tomb1[10];

    for (int i = 0; i < 10; i += 1)
        tomb1[i] = i * 10;

    int i = 0;
    while (true) {
        printf("%d. elem: %d\n", i, tomb1[i]);
        i += 1;
    }


    //5.1
    int tomb2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int minhely = 0;

    printf("A tomb:");
    for(int i = 0; i < 10; i++) {
        printf(" [%d]=%d", i, tomb2[i]);
        if(tomb2[i] < minhely) {
            minhely = i;
        }
    }
    printf("\nA legkisebb szam: %d", minhely);
    printf("\nA legkisebb indexe: %d", tomb2[minhely]);


    //5.2.
    int tomb[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int minhely2 = 0;

    for(int i = 0; i < 10; i++) {
        if(tomb[i] < minhely2) {
            minhely2 = i;
        }
    }

    printf("A tomb:");
    for(int i = 0; i < 10; i++) {
        printf(" %d", tomb[i]);
        if(tomb[i] == tomb[minhely2]) {
            printf("[MIN]");
        }
    }

    printf("\nA legkisebb szam: %d", minhely2);
    printf("\nA legkisebb indexe: %d", tomb[minhely2]);


    //6.
    char p[10] = {'P', 'i', 't', 'a', 'g', 'o', 'r', 'a', 's', 'z'};

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            printf(" %c", p[(i + j)%10]);
        }
        printf("\n");
    }
}




