#ifndef FAJLKEZELES_H
#define FAJLKEZELES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "debugmalloc.h"

typedef struct Asztal
{
    int pozX;
    int pozY;
    int fo;
    int foglaltsag;
} Asztal;

typedef struct Etel
{
    char etelNev[50 + 1];
    int ar;
} Etel;

typedef struct Etelcsoport
{
    char etelcsoportNev[50 + 1];
    Etel *etelek;
} Etelcsoport;

Asztal *asztalokBeolvas(int *listaHossz);
Etelcsoport *kajamenuBeolvas(int **meretek, int *meretekHossz);
#endif