#ifndef FOMENU_H
#define FOMENU_H

#include <stdio.h>

#include "fajlkezeles.h"
#include "structs.h"

void fomenuKiir(void);
int fomenu(Asztal **asztalok, int *asztalokHossz, Etelcsoport **menu, int **meretek, int *meretekHossz, Rendeles **rendelesek, int *rendelesekHossz);

#endif
