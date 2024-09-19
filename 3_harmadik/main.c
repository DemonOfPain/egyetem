#include <stdio.h>
#include <math.h>
#include <stdbool.h>

double kob(double x);

double abszolut(double x);

int maganhangzoe(char c);

typedef struct Pont {
    double x, y;
} Pont;

typedef struct Datum {
    int ev, ho, nap;
} Datum;

typedef struct Versenyzo {
    char nev[31];
    Datum szuletes;
    int helyezes;
} Versenyzo;

void datum_kiir(Datum d);

void versenyzo_kiir(Versenyzo v);

//feladatok:
//1.
void tombfrissito(void);
//2.
void fuggvenyalapok(void);
//3.
void madarnyelv(void);
//4.
void pontok(void);
//5.
void adatszerkezetek(void);
//6.
void menuvezerelt(void);

int alapertekVissza (int x);
int pluszEgy (int x);
int negalas (int x);
int szorKetto (int x);
//----------

int main(void) {
    //1.
    tombfrissito();
    printf("\n------\n\n");
    //2.
    fuggvenyalapok();
    printf("\n------\n\n");
    //3.
    madarnyelv();
    printf("\n------\n\n");
    //4.
    pontok();
    printf("\n------\n\n");
    //5.
    adatszerkezetek();
    printf("\n------\n\n");
    //6.
    menuvezerelt();

    return 0;
}

double kob(double x) {
    return x * x * x;
}

double abszolut(double x) {
    if(x < 0) {
        return -x;
    } else {
        return x;
    }
}

int maganhangzoe(char c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return 0;
    } else if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return 1;
    } else {
        return -1;
    }
}

void datum_kiir(Datum d) {
    printf("%d. %d. %d.", d.ev, d.ho, d.nap);
}

void versenyzo_kiir(Versenyzo v) {
    printf("Nev: %s\n", v.nev);
    printf("Szuletes: ");
    datum_kiir(v.szuletes);
    printf("\nHelyezes: %d\n", v.helyezes);
}

//feladatok:
void tombfrissito(void) {
    double szamok[10] = { -2.5, -69, 5.4, -8, -7.7, 6, 2.9, -10, -3, 9.8 };
    int negativak[10] = {0};
    int negativakSzama = 0;

    // Az eredeti tömb kiírása
    printf("Osszesen %d szam van.\n", 10);

    for(int i = 0; i < 10; ++i) {
        printf("[%d]=%g ", i, szamok[i]);

        if(szamok[i] < 0) {
            negativak[negativakSzama] = i;
            negativakSzama++;
        }
    }
    printf("\n\n");

    //negativak kiirasa
    printf("Ebbol %d szam negativ.\n", negativakSzama);

    for(int i = 0; i < negativakSzama; i++) {
        printf("[%d]=%.1f ", negativak[i], szamok[negativak[i]]);
    }
}

void fuggvenyalapok(void) {
    for(double a = -1; a <= 1; a += .1) {
        printf("%.4f | %.4f | %.4f | %.4f\n", a, kob(a), abszolut(a), sin(a));
    }
}

void madarnyelv(void) {
    char c;
    while (scanf("%c", &c) != EOF) {
        switch(maganhangzoe(c)) {
        case 0:
            printf("%cv%c", c, c);
            break;

        case 1:
            printf("%cv%c", c, c + 32);
            break;

        case -1:
            printf("%c", c);

        }
    }
}

void pontok(void) {
    Pont pont1 = {2.2, 1.6};
    Pont pont2;

    printf("Add meg az x koordinatat: ");
    scanf("%lf", &pont2.x);
    printf("Add meg az y koordinatat: ");
    scanf("%lf", &pont2.y);

    Pont pontFelezo = {(pont1.x + pont2.x) / 2.0, (pont1.y + pont2.y) / 2.0};
    printf("A felezo:\nx: %f\ny: %f", pontFelezo.x, pontFelezo.y);
}

void adatszerkezetek(void) {
    Versenyzo versenyzok[5] = {
        { "Am Erika", {1984, 5, 6}, 1 },
        { "Break Elek", {1982, 9, 30}, 3 },
        { "Dil Emma", {1988, 8, 25}, 2 },
        { "Kasza Blanka", {1979, 6, 10}, 5 },
        { "Reset Elek", {1992, 4, 5}, 4 },
    };

    //0-s versenyzõ neve
    printf("%s", versenyzok[0].nev);
    printf("\n");
    //2-es versenyzõ helyezése
    printf("%d", versenyzok[2].helyezes);
    printf("\n");
    //4-es versenyzõ születési dátuma
    datum_kiir(versenyzok[4].szuletes);
    printf("\n");
    //1-es versenyzõ nevének kezdõbetûje
    printf("%c", versenyzok[1].nev[0]);
    printf("\n");
    //az 1-es versenyzõ dobogós-e
    printf((versenyzok[1].helyezes <= 3) ? "igen" : "nem");
    printf("\n");
    //az 4-es versenyzõ gyorsabb-e, mint a 3-as versenyzõ?
    printf((versenyzok[4].helyezes < versenyzok[3].helyezes) ? "igen" : "nem");
    printf("\n");
    //az 1-es versenyzõ ugyanabban az évben született-e, mint a 2-es?
    printf((versenyzok[1].szuletes.ev == versenyzok[2].szuletes.ev) ? "igen" : "nem");
    printf("\n");
    //1-es versenyzõ összes adata
    versenyzo_kiir(versenyzok[1]);
    printf("\n");
    //összes versenyzõ sorszámozva, összes adatukkal
    for(int i = 0; i < 5; i++) {
        printf("Versenyzo sorszama: %d\n", i);
        versenyzo_kiir(versenyzok[i]);
        printf("\n");
    }
}

void menuvezerelt(void) {
    int a = 1;
    bool menufut = true;

    do {
        int menupont;

        printf("\n-----\na = %d\nMenu:\n", a);
        printf("0. Alapertek visszaallitasa (a = 1)\n"
               "1. Hozzaad 1-et\n"
               "2. Megforditja az elojelet\n"
               "3. Szorozza 2-vel\n"
               "9. Kilepes\n"
               "Valasztott menupont: ");
        scanf("%d", &menupont);

        switch(menupont) {
        case 0:
            a = alapertekVissza(1);
            break;
        case 1:
            a = pluszEgy(a);
            break;
        case 2:
            a = negalas(a);
            break;
        case 3:
            a = szorKetto(a);
            break;
        case 9:
            menufut = false;
            break;

        };

    } while(menufut);

}

int alapertekVissza(int alapertek) {
    return alapertek;
}
int pluszEgy(int szam) {
    return szam + 1;
}
int negalas(int szam) {
    return -szam;
}
int szorKetto(int szam) {
    return szam * 2;
}
