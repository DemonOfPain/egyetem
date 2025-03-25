#ifndef BICIKLI_H
#define BICIKLI_H
#include <iostream>

class Jarmu
{
    double vMax;

public:
    Jarmu(double v) : vMax(v)
    {

        std::cout << "\tJarmu ctor vMax=" << vMax << std::endl;
    }
    Jarmu(const Jarmu &j) : vMax(j.vMax)
    {

        std::cout << "\tJarmu copy vMax=" << vMax << std::endl;
    }
    virtual ~Jarmu()
    {

        std::cout << "\tJarmu dtor vMax=" << vMax << std::endl;
    }
};
class Szan : public Jarmu
{
    int kutyakSzama;

public:
    Szan(double v = 0, int n = 0) : Jarmu(v), kutyakSzama(n)
    {
        std::cout << "\tSzan ctor kutyakSzama=" << kutyakSzama << std::endl;
    }
    Szan(const Szan &sz) : Jarmu(sz), kutyakSzama(sz.kutyakSzama)
    {
        std::cout << "\tSzan copy kutyakSzama=" << kutyakSzama << std::endl;
    };
    ~Szan()
    {
        std::cout << "\tSzan dtor kutyakSzama=" << kutyakSzama << std::endl;
    }
};
class Kerek
{
    int atmero;

public:
    Kerek(int a) : atmero(a) { std::cout << "\tKerek ctor\n"; }
    virtual ~Kerek() { std::cout << "\tKerek dtor\n"; }
    Kerek(const Kerek &k) : atmero(k.atmero) { std::cout << "\tKerek copy\n"; }
    void kiir() { std::cout << "atmero=" << atmero << std::endl; }
};
class Bicikli : public Jarmu
{
    Kerek elso;
    Kerek hatso;

public:
    Bicikli(double v, int d) : Jarmu(v), elso(d), hatso(d)
    {
        std::cout << "\tBicikli ctor ";
        elso.kiir();
    }

    Bicikli(Bicikli &b) : Jarmu(b), elso(b.elso), hatso(b.hatso)
    {

        std::cout << "\tBicikli copy ";

        elso.kiir();
    }
    ~Bicikli()
    {

        std::cout << "\tBicikli dtor ";

        elso.kiir();
    }
};

#endif