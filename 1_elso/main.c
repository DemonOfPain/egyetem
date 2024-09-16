#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    //1.hello world!
    printf("Hello world!\n")


    //5.tartaly

    float magassag;
    float atmero;
    float sugar;

    printf("Tartaly festese\n\n");

    printf("Milyen magas? ");
    scanf("%f", &magassag);

    printf("Mennyi az atmeroje? ");
    scanf("%f", &atmero);

    sugar = atmero / 2;

    float dobozDb = (2 * (sugar * sugar * 3.14) + (2 * sugar * 3.14 * magassag)) / 2;

    printf("\n%f doboz festek kell.", dobozDb);



    //6.masodfoku diszkutalas

    float a;
    float b;
    float c;

    printf("Add meg a masodfoku egyenlet egyutthatoit(ax^2 + bx + c): \n");

    printf("a: ");
    scanf("%f", &a);
    printf("b: ");
    scanf("%f", &b);
    printf("c: ");
    scanf("%f", &c);

    float diszkriminans = b * b - 4 * (a * c);

    if(diszkriminans < 0){
        printf("Nincs megoldasa az egyenletnek");
    }
    if(diszkriminans == 0){
        printf("1 megoldasa van az egyenletnek");
    }
    if(diszkriminans > 0){
        printf("2 megoldasa van az egyenletnek");
    }



    //7.szamok kiirasa

    for(int counter = 1; counter <= 20; counter++){
        printf("%i\n", counter);
    }



    //8.vonal

    int hossz;

    printf("Add meg a szakasz hosszat: ");
    scanf("%d", &hossz);

    printf("+");
    for(int i = 0; i < hossz; i++) {
        printf("-");
    }

    printf("+");



    //9.masodfoku

    float a;
    float b;
    float c;

    printf("Add meg a masodfoku egyenlet egyutthatoit(ax^2 + bx + c): \n");

    printf("a: ");
    scanf("%f", &a);
    printf("b: ");
    scanf("%f", &b);
    printf("c: ");
    scanf("%f", &c);

    float diszkriminans = b * b - 4 * (a * c);

    if(diszkriminans < 0)
    {
        printf("Nincs megoldasa az egyenletnek");
    }
    else
    {
        float x;
        float y;

        x = (sqrt(diszkriminans) - b) / (2 * a);
        y = (- sqrt(diszkriminans) - b) / (2 * a);

        if(x == y)
        {
            printf("A megoldas: %f", x);
        }
        else
        {
            printf("A megoldasok: %f, %f", x, y);
        }
    }

    return 0;

}
