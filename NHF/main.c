#include <stdio.h>
#include <windows.h>

#include "debugmalloc.h"
#include "fomenu.h"
#include "fajlkezeles.h"

int main()
{
    int asztalokHossz = 0;
    Asztal *asztalok = asztalokBeolvas(&asztalokHossz);

    int *meretek = NULL;
    int meretekHossz = 0;
    Etelcsoport *menu = kajamenuBeolvas(&meretek, &meretekHossz);

    int fomenuFut = 1;
    while (fomenuFut)
    {
        fomenuFut = fomenu(&asztalok, &asztalokHossz, menu, meretek, meretekHossz);
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
    return 0;
}
