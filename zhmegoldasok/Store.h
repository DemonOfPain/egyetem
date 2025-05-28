#pragma once
/*
	Egész számok tárolásához készítettük az alábbi osztályt (Store), ami dinamikus memóriában 
	létrehozott tömbben tárolja az adatokat.
*/

// store.h
#include <iostream>

class Store {
    int* data; // pointer a tárolóra
    int nVal; // aktuális darabszám
public:
    Store() : data(nullptr), nVal(0) {}
    ~Store() { delete[] data; }
    Store& operator=(const Store&);
    void add(int);

    void list(std::ostream& os) const { // kiírja az adatokat vesszõvel elválasztva
        for (int i = 0; i < nVal; ++i) {
            os << (i > 0 ? ", " : "") << data[i]; // elõd elõtt nincs vesszõ
        }
        os << std::endl;
    }

    virtual ~Store() { delete[] data; }
};

/*
    Sajnos a store.cpp fájl elveszett, amiben az osztály inline függvényei (copyctor, op=, add) 
    definiálták. Készítse el a hiányzó kívüli definiált tagfüggvényeket úgy, hogy az osztály 
    használatakor ne lépjen fel memóriakezelési hibat Mûködjön helyesen az alábbi kódrészlet:    

    Store s1;
    s1.add(2);
    s1.add(3);
    s1.list(std::cout); // KIÍR: 2, 3
    for (int i = 0; i < 3; ++i) s1.add(i+10);
    Store s2 = s1;
    Store s3;
    s3 = s2 = s1;
    s3.list(std::cout); // KIÍR: 2, 3, 10, 11, 12
*/

//==============================================================================================================

// !!! Raktarrol loptam ezt a megoldast !!!

// store.cpp -> kikommenteltem mert ez itt nem kell
// #include "store.h" -> kikommenteltem mert ez itt nem kell

// Itt készítse el a tagfüggvényeket!
// Ahol szükséges, hogy mit készített el, tegye definiálttá a megfelelõ makrót (törölje a //-t):
//#define VAN_ADD // ha kész a add tagfüggvény
//#define VAN_COPY // ha kész a copy konstruktor
//#define VAN_ASSIGN // ha kész az op=
// <- itt erre nincs szukseg

void Store::add(int szam) {
    int* uj;
    uj = new int[nVal + 1];
    for (size_t i = 0; i < nVal; i++) {
        uj[i] = data[i];
    }
    uj[nVal] = szam;
    delete[] data;
    data = uj;
    nVal++;
}

Store::Store(const Store& rhs) {
    nVal = rhs.nVal;
    data = new int[nVal];
    for (size_t i = 0; i < nVal; i++) {
        data[i] = rhs.data[i];
    }
}

Store& Store::operator=(const Store& rhs) {
    if (this != &rhs) {
        delete[] data;
        nVal = rhs.nVal;
        data = new int[nVal];
        for (size_t i = 0; i < nVal; i++) {
            data[i] = rhs.data[i];
        }
    }
    return *this;
}