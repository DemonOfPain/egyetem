#include <stdio.h>
#include <windows.h>

#include "fomenu.h"
#include "fajlkezeles.h"

int main()
{
    // Asztal *asztalok = asztalokBeolvas();
    // printf("%d %d %d", asztalok[1].pozX, asztalok[1].pozY, asztalok[1].fo);
    // free(asztalok);

    int *meretek = NULL;
    int meretekHossz;
    Etelcsoport *menu = kajamenuBeolvas(&meretek, &meretekHossz);

    int fomenuFut = 1;
    while (fomenuFut)
    {
        fomenuFut = fomenu(menu, meretek, meretekHossz);
    }

    for (int i = 0; i < meretekHossz; i++)
    {
        for (int j = 0; j < meretek[i]; j++)
        {
            free(menu[i].etelek);
        }
    }
    free(menu);
    free(meretek);
    return 0;
}
