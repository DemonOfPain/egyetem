#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "debugmalloc.h"

typedef struct Asztal
{
    int pozX;
    int pozY;
    int fo;
} Asztal;

typedef struct Etel
{
    char etelNev[50 + 1];
    int ar;
} Etel;

typedef struct Etelcsoport
{
    char etelcsoportNev[50 + 1];
    Etel *etelek;
} Etelcsoport;

Asztal *asztalokBeolvas(int *asztalokListaHossz)
{
    FILE *asztalokFajl = fopen("asztalok.txt", "r");
    if (asztalokFajl == NULL)
    {
        printf("Asztalok.txt beolvasasa sikertelen!");
        return NULL;
    }

    Asztal *asztalok = NULL;
    int asztalokSzama = 0;
    if (fscanf(asztalokFajl, "%d", &asztalokSzama) == 1 && asztalokSzama > 0)
    {
        asztalok = malloc(asztalokSzama * sizeof(Asztal));
    }
    else
    {
        printf("Asztalok.txt beolvasasa sikertelen!");
        fclose(asztalokFajl);
        return NULL;
    }

    Asztal beolvasott;
    int i = 0;
    while (fscanf(asztalokFajl, "%d %d %d", &beolvasott.pozX, &beolvasott.pozY, &beolvasott.fo) == 3)
    {
        if (beolvasott.pozX < 0 || beolvasott.pozY < 0 || beolvasott.fo < 1)
        {
            printf("Asztalok.txt beolvasasa sikertelen!");
            fclose(asztalokFajl);
            free(asztalok);
            return NULL;
        }

        asztalok[i] = beolvasott;
        i++;
    }
    *asztalokListaHossz = i;

    if (i == 0)
    {
        fclose(asztalokFajl);
        free(asztalok);
        return NULL;
    }
    else
    {
        fclose(asztalokFajl);
        return asztalok;
    }
}

Etelcsoport *kajamenuBeolvas(int **meretekLista, int *meretekListaHossz)
{
    FILE *menuFajl = fopen("menu.txt", "r");
    if (menuFajl == NULL)
    {
        printf("Menu.txt beolvasasa sikertelen!");
        return NULL;
    }

    Etelcsoport *menu = NULL;
    int etelcsoportokSzama = 0;
    if (fscanf(menuFajl, "%d", &etelcsoportokSzama) == 1 && etelcsoportokSzama > 0)
    {
        menu = malloc(etelcsoportokSzama * sizeof(Etelcsoport));
        if (menu == NULL)
        {
            printf("Menu.txt beolvasasa sikertelen!");
            return NULL;
        }
        for (int i = 0; i < etelcsoportokSzama; i++)
        {
            menu[i].etelek = NULL;
        }
    }
    else
    {
        printf("Menu.txt beolvasasa sikertelen!");
        fclose(menuFajl);
        return NULL;
    }
    *meretekListaHossz = etelcsoportokSzama;

    char beolvasottEtelcsoportNev[50 + 1];
    for (int i = 0; i < etelcsoportokSzama && fscanf(menuFajl, " %s", beolvasottEtelcsoportNev) == 1; i++)
    {
        strcpy(menu[i].etelcsoportNev, beolvasottEtelcsoportNev);
    }

    int *meretek = malloc(etelcsoportokSzama * sizeof(int));
    for (int i = 0; i < etelcsoportokSzama; i++)
    {
        meretek[i] = 0;
    }

    int beolvasandoEtelekSzama;
    fscanf(menuFajl, "%d", &beolvasandoEtelekSzama);

    int etelcsoportId;
    char etelNev[50 + 1];
    int ar;

    for (int i = 0; i < beolvasandoEtelekSzama; i++)
    {
        if (fscanf(menuFajl, "%d", &etelcsoportId) != 1)
            break;
        if (fscanf(menuFajl, " %[^\n]", etelNev) != 1)
            break;
        if (fscanf(menuFajl, "%d", &ar) != 1)
            break;

        Etel *ujEtelek = realloc(menu[etelcsoportId].etelek,
                                 (meretek[etelcsoportId] + 1) * sizeof(Etel));
        if (ujEtelek == NULL)
            break;

        menu[etelcsoportId].etelek = ujEtelek;
        strcpy(menu[etelcsoportId].etelek[meretek[etelcsoportId]].etelNev, etelNev);
        menu[etelcsoportId].etelek[meretek[etelcsoportId]].ar = ar;
        meretek[etelcsoportId]++;
    }

    *meretekLista = meretek;
    fclose(menuFajl);
    return menu;
}