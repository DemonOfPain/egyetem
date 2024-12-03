#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "debugmalloc.h"
#include "structs.h"

#define YELLOW "\033[0;33m"
#define LIGHT_YELLOW "\033[38;2;255;255;192m"
#define WHITE "\033[0;37m"
#define RED "\033[0;31m"
#define LIGHT_RED "\033[38;2;255;224;224m"
#define GREEN "\033[0;32m"
#define LIGHT_GREEN "\033[38;2;224;255;224m"

Asztal *asztalokBeolvas(int *asztalokListaHossz)
{
    FILE *asztalokFajl = fopen("asztalok.txt", "r");
    if (asztalokFajl == NULL)
    {
        printf(RED "\nAsztalok.txt beolvasasa sikertelen!\n" WHITE);
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
        printf(RED "\nAsztalok.txt beolvasasa sikertelen!\n" WHITE);
        fclose(asztalokFajl);
        return NULL;
    }

    Asztal beolvasott;
    int i = 0;
    while (fscanf(asztalokFajl, "%d %d %d", &beolvasott.pozX, &beolvasott.pozY, &beolvasott.fo) == 3)
    {
        if (beolvasott.pozX < 0 || beolvasott.pozY < 0 || beolvasott.fo < 1)
        {
            printf(RED "\nAsztalok.txt beolvasasa sikertelen!\n" WHITE);
            fclose(asztalokFajl);
            free(asztalok);
            return NULL;
        }
        beolvasott.foglaltsag = 0;
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
        printf(RED "\nMenu.txt beolvasasa sikertelen!\n" WHITE);
        return NULL;
    }

    Etelcsoport *menu = NULL;
    int etelcsoportokSzama = 0;
    if (fscanf(menuFajl, "%d", &etelcsoportokSzama) == 1 && etelcsoportokSzama > 0)
    {
        menu = malloc(etelcsoportokSzama * sizeof(Etelcsoport));
        if (menu == NULL)
        {
            printf(RED "\nMenu.txt beolvasasa sikertelen!\n" WHITE);
            return NULL;
        }
        for (int i = 0; i < etelcsoportokSzama; i++)
        {
            menu[i].etelek = NULL;
        }
    }
    else
    {
        printf(RED "\nMenu.txt beolvasasa sikertelen!\n" WHITE);
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

        Etel *ujEtelek = realloc(menu[etelcsoportId].etelek, (meretek[etelcsoportId] + 1) * sizeof(Etel));
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

int asztalokMent(Asztal *asztalok, int asztalokHossz)
{
    if (!asztalok)
    {
        return 1;
    }

    FILE *asztalokFajl = fopen("asztalok.txt", "w");
    if (asztalokFajl == NULL)
    {
        return 1;
    }

    fprintf(asztalokFajl, "%d\n", asztalokHossz);
    for (int i = 0; i < asztalokHossz; i++)
    {
        fprintf(asztalokFajl, "%d %d %d\n", asztalok[i].pozX, asztalok[i].pozY, asztalok[i].fo);
    }

    fclose(asztalokFajl);
    return 0;
}

int kajamenuMent(Etelcsoport *menu, int *meretek, int meretekHossz)
{
    if (!menu || !meretek)
    {
        return 1;
    }

    FILE *menuFajl = fopen("menu.txt", "w");
    if (menuFajl == NULL)
    {
        return 1;
    }

    fprintf(menuFajl, "%d\n", meretekHossz);
    for (int i = 0; i < meretekHossz; i++)
    {
        fprintf(menuFajl, "%s\n", menu[i].etelcsoportNev);
    }

    int osszEtel = 0;
    for (int i = 0; i < meretekHossz; i++)
    {
        osszEtel += meretek[i];
    }
    fprintf(menuFajl, "%d\n", osszEtel);

    for (int i = 0; i < meretekHossz; i++)
    {
        for (int j = 0; j < meretek[i]; j++)
        {
            fprintf(menuFajl, "%d\n%s\n%d\n", i, menu[i].etelek[j].etelNev, menu[i].etelek[j].ar);
        }
    }

    fclose(menuFajl);
    return 0;
}
