#include <stdio.h>
#include <windows.h>
#include "menu.h"

int main(){
    foMenuKiir();

    int a;
    while (scanf("%d", &a) && a!=-1)
    {
        system("@cls");
        foMenuKiir();
    }
    

    return 0;
}
