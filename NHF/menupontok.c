#include <stdio.h>
#include <windows.h>

#include "fajlkezeles.h"

#define YELLOW "\033[0;33m"
#define WHITE "\033[0;37m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"

int asztalokMegadasa(Asztal **asztalok, int *asztalokHossz)
{
    system("@cls");
    printf(YELLOW "Asztalok megadasa\n" WHITE);

    int x;
    int y;
    int fo;

    if (scanf("%d %d %d", &x, &y, &fo) < 3)
    {
        return 1;
    }

    for (int i = 0; i < *asztalokHossz; i++)
    {
        if ((*asztalok)[i].pozX == x && (*asztalok)[i].pozY == y)
        {
            char valasz;
            printf("Ezen a pozicion mar van asztal, felulirod? (i/n) ");
            scanf(" %c", &valasz);
            if (valasz == 'i')
            {
                (*asztalok)[i].pozX = x;
                (*asztalok)[i].pozY = y;
                (*asztalok)[i].fo = fo;
                (*asztalok)[i].foglaltsag = 0;

                printf("Asztal id: %d felulirva, uj ertekek:\n\tkoordinatak: %d %d\n\tfo: %d\n\tfoglaltsag: szabad\n", i, x, y, fo);

                return 0;
            }
            else
            {
                printf(RED "Hibas valasz!" WHITE);
            }
        }
    }
    // nincs ellenorzes de statisztikailag kizart hogy ne legyen ra memoria
    *asztalok = realloc(*asztalok, (*asztalokHossz + 1) * sizeof(Asztal));
    (*asztalok)[*asztalokHossz].pozX = x;
    (*asztalok)[*asztalokHossz].pozY = y;
    (*asztalok)[*asztalokHossz].fo = fo;
    (*asztalok)[*asztalokHossz].foglaltsag = 0;
    (*asztalokHossz)++;
    printf("Asztal id: %d felveve, ertekek:\n\tkoordinatak: %d %d\n\tfo: %d\n\tfoglaltsag: szabad\n", *asztalokHossz - 1, x, y, fo);

    return 0;
}

int kajaMenu(Etelcsoport *menu, int *meretek, int meretekHossz)
{
    system("@cls");
    printf(YELLOW "Menu\n" WHITE);
    printf("1. Menu kiir\n");
    printf("2. Etelcsoport megadasa\n");
    printf("3. Etel megadasa\n");

    int valasztas = 0;
    scanf("%d", &valasztas);

    switch (valasztas)
    {
    case 1:
        for (int i = 0; i < meretekHossz; i++)
        {
            printf("Etelcsoport: %s\n", menu[i].etelcsoportNev);
            for (int j = 0; j < meretek[i]; j++)
            {
                printf("  Etel: %s, Ar: %d\n", menu[i].etelek[j].etelNev, menu[i].etelek[j].ar);
            }
        }
        system("pause");
    case 2:

    case 3:
    }
    return 0;
}

int asztalFoglalasok(Asztal *asztalok, int asztalokHossz)
{
    system("@cls");
    printf(YELLOW "Asztal foglalasok\n" WHITE);
    printf("A kovetkezokeppen adjad meg a parametereket:");
    printf("asztalid foglaltsag (szokozzel elvalasztva!) Ha a foglaltsag 1 akkor foglalt ha 0 akkor szabad.");
    printf("A foglaltsag mindig az uj megadott lesz, meg ha meg is egyezik a regivel.\n");

    int asztalId = -1;
    int foglaltsag = -1;

    int input = scanf("%d %d", &asztalId, &foglaltsag);

    if (input == 2 && asztalId >= 0 && (foglaltsag == 0 || foglaltsag == 1) && asztalId < asztalokHossz)
    {
        asztalok[asztalId].foglaltsag = foglaltsag;

        printf("Asztal id: %d, uj foglaltsaga: %s.\n", asztalId, foglaltsag ? "foglalt" : "szabad");
        system("pause");
        return 0;
    }
    else
    {
        return 1;
    }
}

int rendelesek(void)
{
    system("@cls");
    printf("Rendelesek\n");
    return 0;
}

int szamlaKiir(void)
{
    system("@cls");
    printf("5. Szamla kiirasa\n");
    return 0;
}

int foglaltsagiTerkepKiir(Asztal *asztalok, int asztalokHossz)
{
    system("@cls");
    printf(YELLOW "Foglaltsagi terkep\n" WHITE);

    system("pause");

    int xMax = 0;
    int yMax = 0;
    for (int i = 0; i < asztalokHossz; i++)
    {
        xMax = asztalok[i].pozX > xMax ? asztalok[i].pozX : xMax;
        yMax = asztalok[i].pozY > yMax ? asztalok[i].pozY : yMax;
    }

    for (int sor = 0; sor <= yMax; sor++)
    {
        for (int oszlop = 0; oszlop <= xMax; oszlop++)
        {
            int printed = 0;
            for (int i = 0; i < asztalokHossz; i++)
            {
                if (asztalok[i].pozX == oszlop && asztalok[i].pozY == sor)
                {
                    if (asztalok[i].foglaltsag == 1)
                    {
                        printf(RED "%d ", i);
                    }
                    else
                    {
                        printf(GREEN "%d ", i);
                    }

                    printed = 1;
                    break;
                }
            }
            if (!printed)
            {
                printf("- ");
            }
            printed = 0;
        }
        printf(WHITE "\n\n");
    }

    system("pause");
    return 0;
}
