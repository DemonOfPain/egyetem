#include <iostream>
/// Utasítást kiíró és végrehajtó makró
#define _(x)  std::cout << #x << std::endl; x

class Jarmu {
    double vMax;
public:
    Jarmu(double v) :vMax(v) {
        std::cout << "\tJarmu ctor vMax="<< v <<"\n";
    }
    Jarmu(Jarmu &j) : vMax(j.vMax) {
        std::cout << "\tJarmu copy vMax="<< j.vMax <<"\n";
    }
    ~Jarmu(){
        std::cout << "\tJarmu dtor vMax="<< this->vMax <<"\n";
    }
};
 
class Szan : public Jarmu {
    int kutyakSzama;
public:
    Szan(double v = 0, int n = 0) :Jarmu(v), kutyakSzama(n) {
        std::cout << "\tSzan ctor kutyakSzama="<< n <<"\n";
    }
    Szan(Szan &sz) : kutyakSzama(sz.kutyakSzama), Jarmu(sz) {
        std::cout << "\tSzan copy kutyakSzama="<< sz.kutyakSzama <<"\n";
    }
    ~Szan(){
        std::cout << "\tSzan dtor kutyakSzama="<< this->kutyakSzama <<"\n";
    }
};

 
int main() {
_(    Szan sz0_obj;             )
_(    Szan sz1_obj(1.1, 1);     )
_(    Szan sz1m_obj = sz1_obj;  )
_(    return 0;                 )
}

