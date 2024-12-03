#ifndef FAJLKEZELES_H
#define FAJLKEZELES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "debugmalloc.h"
#include "structs.h"

Asztal *asztalokBeolvas(int *listaHossz);
Etelcsoport *kajamenuBeolvas(int **meretek, int *meretekHossz);
int asztalokMent(Asztal *asztalok, int asztalokHossz);
int kajamenuMent(Etelcsoport *menu, int *meretek, int meretekHossz);
#endif
