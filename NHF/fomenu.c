#include <stdio.h>
#include <windows.h>

#include "fajlkezeles.h"

#define YELLOW "\033[0;33m"
#define WHITE "\033[0;37m"
/**
 * @file menu.c
 * @brief főmenüt kezelő modul
 */

void fomenuKiir(void)
{
    printf(YELLOW "FOMENU\n\n" WHITE);
    printf("1. Asztalok megadasa\n");
    printf("2. Menu\n");
    printf("3. Asztal foglalasok\n");
    printf("4. Rendelesek\n");
    printf("5. Szamla kiirasa\n");
    printf("6. Foglaltsagi terkep megjelenitese\n");
    printf("7. Kilep\n");
}

int asztalokMegadasa(void)
{
    system("@cls");
    printf(YELLOW "Asztalok megadasa\n" WHITE);
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

int asztalFoglalasok(void)
{
    system("@cls");
    printf("Asztal foglalasok\n");
    return 0;
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

int foglaltsagiTerkepKiir(void)
{
    system("@cls");
    printf("Foglaltsagi terkep\n");
    return 0;
}

int fomenu(Etelcsoport *menu_2, int *meretek_2, int meretekHossz_2)
{
    system("@cls");
    fomenuKiir();
    int menupont = 0;
    while (!menupont)
    {
        if (scanf("%d", &menupont) != 1 || menupont < 1 || menupont > 7)
        {
            printf("Helytelen menupont!\n");
            menupont = 0;
        }
    }

    switch (menupont)
    {
    case 1:
        asztalokMegadasa();
        return 1;
    case 2:
        kajaMenu(menu_2, meretek_2, meretekHossz_2);
        return 1;
    case 3:
        asztalFoglalasok();
        return 1;
    case 4:
        rendelesek();
        return 1;
    case 5:
        szamlaKiir();
        return 1;
    case 6:
        foglaltsagiTerkepKiir();
        return 1;
    case 7:
        return 0;
    default:
        return 0;
    }
}