/**
 *  \file szakasz.cpp
 *  Szakasz oszt�ly tagf�ggv�nyeinek megval�s�t�sa
 */
#include "szakasz.h"

/// Szakaszt rajzol� rajzol fv.
void Szakasz::rajzol() const {
    std::cout << "Rajzol: " << *this << std::endl;
}

/// Glob�lis << oper�tor a Szakasz adatainak ki�r�s�hoz
std::ostream& operator<<(std::ostream& os, const Szakasz& sz) {
    return os << "Szakasz " << (Alakzat&)sz << ",pv=" << sz.getpv();
}
