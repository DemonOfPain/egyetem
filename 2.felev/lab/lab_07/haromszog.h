/**
 *  \file haromszog.h
 *  Haromszog osztály deklarációja
 */
#include "alakzat.h"
#ifndef HAROMSZOG_H
#define HAROMSZOG_H

/// Ügyeljen arra, hogy a csúcspontokat az alaposztály orgiójához relatívan tárolja!
class Haromszog : public Alakzat {
    Pont p1;
    Pont p2;

    public:
        Haromszog(const Pont& p0, const Pont& p1, const Pont& p2, Szin sz) : Alakzat(p0, sz), p1(p1 - p0), p2(p2 - p0){}

        Pont getP1() const {return getp0()+p1;}
        Pont getP2() const {return getp0()+p2;}

        void rajzol() const;

};

std::ostream& operator<<(std::ostream& os, const Haromszog& h);

#endif // KOR_H
