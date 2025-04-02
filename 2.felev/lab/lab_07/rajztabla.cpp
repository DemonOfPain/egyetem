/**
 *  \file rajztabla.cpp
 *   Ebben a fájlban valósítsa meg a Rajztábla osztály nem inline tagfüggvényeit
 */

#include "rajztabla.h"

void Rajztabla::felrak(Alakzat* a){
    this->tabla[this->db] = a;
    this->db++;
}

void Rajztabla::rajzol() const {
    for(size_t i = 0; i < this->db; i++){
        this->tabla[i]->rajzol();
    }
}

void Rajztabla::mozgat(const Pont& d) const {
    for(size_t i = 0; i < this->db; i++){
        this->tabla[i]->mozgat(d);
    }
}

void Rajztabla::torol(){
    for(size_t i = 0; i < this->db; i++){
        delete this->tabla[i];
    }
    this->db = 0;
}