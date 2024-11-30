#include <stdio.h>
#include <windows.h>

#include "fajlkezeles.h"
#include "menupontok.h"

#define YELLOW "\033[0;33m"
#define WHITE "\033[0;37m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"

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

int fomenu(Asztal *asztalok, int asztalokHossz, Etelcsoport *menu, int *meretek, int meretekHossz)
{
    system("@cls");
    fomenuKiir();
    int menupont = 0;
    while (!menupont)
    {
        if (scanf("%d", &menupont) != 1 || menupont < 1 || menupont > 7)
        {
            printf(RED "Helytelen menupont!\n" WHITE);
            menupont = 0;
        }
    }

    switch (menupont)
    {
    case 1:
        asztalokMegadasa(asztalok, asztalokHossz);
        return 1;
    case 2:
        kajaMenu(menu, meretek, meretekHossz);
        return 1;
    case 3:
        int r = asztalFoglalasok(asztalok, asztalokHossz);
        if (r == 1)
        {
            printf(RED "Hibas parameterek!\n" WHITE);
            system("pause");
        }

        return 1;
    case 4:
        rendelesek();
        return 1;
    case 5:
        szamlaKiir();
        return 1;
    case 6:
        foglaltsagiTerkepKiir(asztalok, asztalokHossz);
        return 1;
    case 7:
        return 0;
    default:
        return 0;
    }
}