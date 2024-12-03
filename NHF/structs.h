#ifndef STRUCTS_H
#define STRUCTS_H

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

typedef struct Rendeles
{
    int asztalId;
    int *etelek;
    int *db;
} Rendeles;

#endif
