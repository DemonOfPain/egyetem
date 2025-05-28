#include "SComplex.h"

Complex::Complex(float r, float i) 
    : r(r), i(i) {}

float Complex::getR() const{
    return r;
}

float Complex::getI() const{
    return i;
}
