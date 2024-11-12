#include <stdio.h>

int main(void) {
    int tprim[6]={2, 3, 5, 7, 11, 13};
    int a=1, b=2;
    int i;

    int *p;

    /* EGYETLEN VÁLTOZÓVAL */
    p=0; p=NULL;   /* nem mutat sehova. */

    printf("a=%d, b=%d\n", a, b);
    p=&a;          /* most a-ra mutat */
    *p=5;
    printf("a=%d, b=%d\n", a, b);
    p=&b;          /* most b-ra mutat */
    *p=9;
    printf("a=%d, b=%d\n", a, b);

    /* TÖMBBEL - tömb elejére mutat, indexelhetõ */
    p=tprim;
    for (i=0; i<6; i++)
        printf("tprim[%d]=%d, p[%d]=%d\n", i, tprim[i], i, p[i]);
    /* a pointerrel végigmegyünk a tömbön */
    /* p++: a következõ elem, nem a következõ bájt! */
    for (i=0, p=tprim; i<6; i++, p++)
        printf("*p=%d\n", *p);

    return 0;
}
