#ifndef MENUPONTOK_H
#define MENUPONTOK_H

#include <stdio.h>

#include "fajlkezeles.h"
#include "structs.h"

int asztalokMegadasa(Asztal **asztalok, int *asztalokHossz);
int kajaMenu(Etelcsoport **menu, int **meretek, int *meretekHossz);
int asztalFoglalasok(Asztal *asztalok, int asztalokHossz);
int rendelesFelvetel(Rendeles **rendelesek, int *rendelesekHossz, Etelcsoport *menu, int *meretek, int meretekHossz);
int szamlaKiir(Rendeles *rendelesek, int rendelesekHossz, Etelcsoport *menu, int *meretek, int meretekHossz);
int foglaltsagiTerkepKiir(Asztal *asztalok, int asztalokHossz);
#endif
