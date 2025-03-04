/*
 * \file teglalap.cpp
 * (Latin-2 kodolasu fajl. Allitsa at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * Egyszer� oszt�ly l�trehoz�sa
 */
#include <iostream>
using std::cout;
using std::endl;

/**
 * Az �n feladata megval�s�tani az egyes tagf�ggv�nyeket.
 * Ahogyan halad a megval�s�t�ssal egyre t�bb tesztesetet kell
 * lefuttatni, ez�rt az ELKESZULT makr� �rt�ket folyamatosan n�velje a
 * feladatsorsz�moknak megfelel�en!
 */
#define ELKESZULT 2

/**
 * Feladatok:
 * 1. ELKESZULT=1
 *    Val�s�tsa meg (defini�lja) a hi�nyz� tagf�ggv�nyeket! (kerulet(), terulet())
 *
 * 2. ELKESZULT=2
 *    Eg�sz�tse ki az oszt�lyt �gy, hogy t�mb is l�trehozhat� legyen bel�le
 *    (Tipp: t�mb csak olyan oszt�lyb�l p�ld�nyos�that�, aminek van param�ter
 *    n�lk�l h�vhat� konstruktora)
 *
 */

class Teglalap {
    double a, b;        // oldalak hossza
public:
    Teglalap();
    Teglalap(double, double);   // konstruktor
    void kiir() const;          // ki�rja az oldalakat
    double kerulet() const;     // ker�let kisz�m�t�sa
    double terulet() const;     // ter�let kisz�m�t�sa
};

Teglalap::Teglalap() {
    this->a = 0;
    this->b = 0;
}

Teglalap::Teglalap(double a, double b) {
    this->a = a;
    this->b = b;
}

void Teglalap::kiir() const {
    cout << "a:" << a << " b:" << b << endl;
}

// ELKESZULT 1
// 1. feladat
double Teglalap::terulet() const {
    return a * b;
}

double Teglalap::kerulet() const{
    return 2 * a + 2 * b;
}



int main() {
    Teglalap ta(1,4);
    cout << "ta: ";
    ta.kiir();
    Teglalap tb(3,8);
    cout << "tb: ";
    tb.kiir();
#if ELKESZULT >= 1
    cout << "ta kerulete:" << ta.kerulet() << endl;
    cout << "tb kerulete:" << tb.kerulet() << endl;
    cout << "ta terulete:" << ta.terulet() << endl;
    cout << "tb terulete:" << tb.terulet() << endl;
#endif

#if ELKESZULT >= 2
    const int N = 5;
    Teglalap teglak[N];
    for (int i = 0; i < N; i++) {
        cout << "teglak[" << i << "]: ";
        teglak[i].kiir();
    }
#endif
    return 0;
}
