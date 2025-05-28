#pragma once
/*
	Tételezze fel, hogy az elõzõ feladatban elkészített Store osztály hibátlanul mûködik, 
	melynek megismételjük a deklarációját:
*/

// store.h
#ifndef STORE_H_INCLUDED
#define STORE_H_INCLUDED
#include <iostream>

class Store {
    int* data; // pointer a tárolóra
    int nVal; // aktuális darabszám
public:
    Store();
    Store(const Store&);
    Store& operator=(const Store&);
    void add(int);
    void list(std::ostream& os) const; // az új adatot a tömb végére teszi

    virtual ~Store();
};

#endif // STORE_H_INCLUDED

/*
    Készítsen inszertert az osztályhoz, ami vesszõvel elválasztva (ugyanúgy, ahogy a list() 
    kiírja a megadott std::ostream-re a tároló tartalmát! Mûködjön helyesen az alábbi kódrészlet:

    Store s1;
    s1.add(2);
    s1.add(3);
    std::cout << s1 << ":" << s1; // KIÍR: 2, 3:2, 3
*/

//==============================================================================================================

// !!! Raktarrol loptam ezt a megoldast !!!


// store.cpp
#include "store.h"

// Itt készítse el a tagfüggvényeket és az inszertert!

std::ostream& operator<<(std::ostream& os, const Store& tag) {
    tag.list(os);
    return os;
}