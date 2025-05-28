/*
	Keszitsen szerizalhato osztalyt a **Complex** es a **Seriazable** osztaly 
	felhasznalasaval. A **SComplex** legyen kompatibilis mindket osztallyal! 
	A fenti osztalyok deklaracioja a kovetkezo:
*/

#pragma once
#include <iostream>

class Complex {
protected:
	float r, i; // r+ij
public:
	Complex(float r, float i);
	float getR() const;
	float getI() const;
};

struct Seriazable {
	virtual void write(std::ostream& os) const = 0;
	virtual void read(std::istream& is) = 0;
};

/*
	Az **SComplex** osztaly **write** fuggvenye a stream-re a kovetkezo formatumban 
	irja ki az objektum adattagjait: "SComplex [r]+[i]\n" (a [x] helyere az adott 
	adattag kerul). A **read** fuggveny pedig ilyen formaban olvassa be a 
	kiszerializalt adatokat. Ha a **read** fuggveny rossz formatumot kap 
	(peldaul rossz nev vagy nem +/j szerepel), akkor kivetelt dob a kovetkezo 
	karakterlanccal: "wrong".
*/

// Megjegyzes: a Complex konstruktora es a setterek az SComplec.cpp-ben vannak,
// azokat nem kell megirni

//==============================================================================================================

class SComplex : public Complex, public Seriazable {
public:
    SComplex(float r = 0.0f, float i = 0.0f) : Complex(r, i) {}

    void write(std::ostream& os) const override {
        os << "SComplex " << r << "+" << i << "\n";
    }

    void read(std::istream& is) override {
        std::string tag;
        char plus;
        float real, imag;

        is >> tag >> real >> plus >> imag;

        if (tag != "SComplex" || plus != '+') {
            throw "wrong";
        }

        r = real;
        i = imag;
    }
};