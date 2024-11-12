#ifndef MENU_H
#define MENU_H
#include <stdio.h>

#define YELLOW "\033[0;33m"
#define WHITE "\033[0;37m"


void foMenuKiir(void){
    printf(YELLOW"FOMENU\n\n"WHITE);
    printf("1. Asztalok megadasa\n");
    printf("2. Menu\n");
    printf("3. Asztal foglalasok\n");
    printf("4. Rendelesek\n");
    printf("5. Szamla kiirasa\n");
    printf("6. Foglaltsagi terkep\n");
    printf("7. Kilep\n");
}

#endif
