#include <stdio.h>
#include <windows.h>

#include "fajlkezeles.h"
#include "menupontok.h"
#include "structs.h"

#define YELLOW "\033[0;33m"
#define LIGHT_YELLOW "\033[38;2;255;255;192m"
#define WHITE "\033[0;37m"
#define RED "\033[0;31m"
#define LIGHT_RED "\033[38;2;255;224;224m"
#define GREEN "\033[0;32m"
#define LIGHT_GREEN "\033[38;2;224;255;224m"

/**
 * @file menu.c
 * @brief főmenüt kezelő modul
 */

void fomenuKiir(void)
{
    printf(YELLOW "FOMENU\n\n" WHITE);
    printf(LIGHT_YELLOW "1. Asztalok megadasa\n");
    printf("2. Menu\n");
    printf("3. Asztal foglalasok\n");
    printf("4. Rendelesek\n");
    printf("5. Szamla kiirasa\n");
    printf("6. Foglaltsagi terkep megjelenitese\n");
    printf(LIGHT_RED "7. Kilep\n" WHITE);
}

int fomenu(Asztal **asztalok, int *asztalokHossz, Etelcsoport **menu, int **meretek, int *meretekHossz, Rendeles **rendelesek, int *rendelesekHossz)
{
    system("@cls");
    fomenuKiir();
    int menupont = 0;
    while (!menupont)
    {
        if (scanf("%d", &menupont) != 1 || menupont < 1 || menupont > 7)
        {
            printf(RED "\nHelytelen menupont!\n" WHITE);
            menupont = 0;
        }
    }

    switch (menupont)
    {
    case 1:
        if (asztalokMegadasa(asztalok, asztalokHossz) == 1)
        {
            printf(RED "\nHibas parameterek!\n" WHITE);
            system("pause");
        }
        return 1;
    case 2:
        kajaMenu(menu, meretek, meretekHossz);
        return 1;
    case 3:
        if (asztalFoglalasok(*asztalok, *asztalokHossz) == 1)
        {
            printf(RED "\nHibas parameterek!\n" WHITE);
            system("pause");
        }

        return 1;
    case 4:
        rendelesFelvetel(rendelesek, rendelesekHossz, *menu, *meretek, *meretekHossz);
        return 1;
    case 5:
        szamlaKiir(*rendelesek, *rendelesekHossz, *menu, *meretek, *meretekHossz);
        return 1;
    case 6:
        foglaltsagiTerkepKiir(*asztalok, *asztalokHossz);
        return 1;
    case 7:
        return 0;
    default:
        printf(RED "\nHelytelen menupont!\n" WHITE);
        return 0;
    }
}
