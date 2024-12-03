#include <stdio.h>
#include <windows.h>

#include "debugmalloc.h"
#include "fomenu.h"
#include "fajlkezeles.h"
#include "structs.h"

#define YELLOW "\033[0;33m"
#define LIGHT_YELLOW "\033[38;2;255;255;192m"
#define WHITE "\033[0;37m"
#define RED "\033[0;31m"
#define LIGHT_RED "\033[38;2;255;224;224m"
#define GREEN "\033[0;32m"
#define LIGHT_GREEN "\033[38;2;224;255;224m"

int main()
{
    // asztalok
    int asztalokHossz = 0;
    Asztal *asztalok = NULL;

    printf("Be szeretned olvasni az elmentett asztalokat? (i/n): " WHITE);
    char valasz_a;
    scanf(" %c", &valasz_a);
    if (valasz_a == 'i')
    {
        asztalok = asztalokBeolvas(&asztalokHossz);
        if (asztalok)
        {
            printf(GREEN "Elmentett asztalok sikeresen beolvasva!\n" WHITE);
        }
    }

    // menu
    int *meretek = NULL;
    int meretekHossz = 0;
    Etelcsoport *menu = NULL;

    printf("Be szeretned olvasni az elmentett menut? (i/n): " WHITE);
    char valasz_m;
    scanf(" %c", &valasz_m);
    if (valasz_m == 'i')
    {
        menu = kajamenuBeolvas(&meretek, &meretekHossz);
        if (menu)
        {
            printf(GREEN "Elmentett menu sikeresen beolvasva!\n" WHITE);
        }
    }
    system("pause");

    // rendelesek
    int rendelesekHossz = 0;
    Rendeles *rendelesek = NULL;

    // fomenu loop
    int fomenuFut = 1;
    while (fomenuFut)
    {
        fomenuFut = fomenu(&asztalok, &asztalokHossz, &menu, &meretek, &meretekHossz, &rendelesek, &rendelesekHossz);
    }

    // mallocok felszabaditasa
    for (int i = 0; i < meretekHossz; i++)
    {
        if (menu[i].etelek)
        {
            free(menu[i].etelek);
        }
    }
    if (asztalok)
    {
        free(asztalok);
    }
    if (menu)
    {
        free(menu);
    }
    if (meretek)
    {
        free(meretek);
    }
    if (rendelesek)
    {
        for (int i = 0; i < rendelesekHossz; i++)
        {
            if (rendelesek[i].etelek)
            {
                free(rendelesek[i].etelek);
            }
            if (rendelesek[i].db)
            {
                free(rendelesek[i].db);
            }
        }
        free(rendelesek);
    }
    return 0;
}
