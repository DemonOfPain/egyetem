#ifndef FOMENU_H
#define FOMENU_H
#include <stdio.h>

#include "fajlkezeles.h"

void fomenuKiir(void);
int fomenu(Etelcsoport *menu_2, int *meretek_2, int meretekHossz_2);

int asztalokMegadasa(void);
int kajaMenu(Etelcsoport *menu, int *meretek, int meretekHossz);
int asztalFoglalasok(void);
int rendelesek(void);
int szamlaKiir(void);
int foglaltsagiTerkepKiir(void);

#endif
