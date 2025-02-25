#include <cstring>
#include <cctype>
#include "nem_oo.h"

/**
 * \file nem_oo_teszt.cpp
 * (UTF-8 kodolasu fajl. Allitsa at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * FELADATOK:
 *  1. Ebben a fájlban valósítsa meg a nem_oo.h állományban deklarált függvényeket!
 *
 * Ügyeljen a helyes névtér használatra!
 *   Tipp: Használja a scope operátort, vagy nyisson névteret!
 */

namespace sajat {
    int atoi(const char *p, int base){
        int ossz = 0;
        for(int i = 0; p[i] != '\0' && p[i] != ' '; i++)
        {
            if(!isdigit(p[i]) || (int)(p[i]) >= base){
                throw "HND2AH";
            }

            int szam = (int)(p[i]);
            ossz = ossz * base + szam;
        }
        return ossz;
    }

    char *strcat(const char *p1, const char *p2){
        int p1len = 0;
        int p2len = 0;
        for(int i = 0; p1[i] != '\0'; i++){
            p1len++;
        }
        for(int i = 0; p2[i] != '\0'; i++){
            p2len++;
        }

        int ujlen = p1len + p2len;
        char* uj = new char[ujlen];

        strcpy(uj, p1);
        ::strcat(uj, p2);

        return uj;
    }

    // char *unique(char *first, char *last){
    // }
}
