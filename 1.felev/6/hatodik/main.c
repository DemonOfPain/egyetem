
#include <stdio.h>

void kocka(double oldal, double *pFelulet, double *pTerfogat);

int *tomb(int t[], int meret, int szam);

int main(void) {
    int t[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("%p\n\n", tomb(t, 10, 4));


    double felulet, terfogat;

    kocka(2.7, &felulet, &terfogat);
    printf("Felulet: %g\n", felulet);
    printf("Terfogat: %g", terfogat);


    return 0;
}

void kocka(double oldal, double *pFelulet, double *pTerfogat) {
    *pFelulet = oldal * oldal;
    *pTerfogat = oldal * oldal * oldal;
}

int *tomb(int t[], int meret, int szam){
    for(int i = 0; i < meret; i++){
        if(t[i] == szam){
            return &t[i];
        }
    }
    return t;
}
