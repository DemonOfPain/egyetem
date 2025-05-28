#include "nem_oo.h"

#include <cctype>
#include <cstring>

/**
 * \file nem_oo.cpp
 * (UTF-8 kodolasu fajl. Allitsa at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * FELADATOK:
 *  1. Ebben a fájlban valósítsa meg a nem_oo.h állományban deklarált
 * függvényeket!
 *
 * Ügyeljen a helyes névtér használatra!
 *   Tipp: Használja a scope operátort, vagy nyisson névteret!
 */

namespace sajat {
    int atoi(const char *p, int base) {
        if (p == NULL || base < 2 || base > 10)
            throw "HND2AH";

        int sum = 0;

        if (*p == '\0')
            throw "HND2AH";

        while (*p != '\0') {
            if (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r')
                break;

            if (!isdigit(*p) || (*p - '0') >= base)
                throw "HND2AH";

            int digit = *p - '0';

            sum = sum * base + digit;

            p++;
        }

        return sum;
    }

    char *strcat(const char *p1, const char *p2) {
        if (p1 == NULL || p2 == NULL)
            return NULL;

        size_t len1 = strlen(p1);
        size_t len2 = strlen(p2);

        char *uj = new char[len1 + len2 + 1];

        strcpy(uj, p1);
        ::strcat(uj, p2);

        return uj;
    }

    char *unique(char *first, char *last) {
        if (first == NULL || last == NULL || first == last)
            return first;

        char *result = first;

        while (++first != last) {
            if (*result != *first) {
                ++result;
                *result = *first;
            }
        }

        return ++result;
    }
}
