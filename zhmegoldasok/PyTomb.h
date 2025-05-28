#pragma once
/*
	Keszitsen adapter sablont (PyTomb) az std::vector tarolohoz, ami atalakitja az **operator[]**
	muveleteket! A tobbi publikus muveletet (konstruktorokat is) valtoztatas nelkul tegye elerhetove!
	A PyTomb adapterrel letrehozott objektum idextiupusa int. Pozitiv ertek eseten normal
	indexmuveletet vegezzen **indexhatar** ellenorzessel! Negativ indexertekek eseten az adatsorozat
	vegetol indexeljen visszafele szinten ellenorzessel! Az PyTomb sablonnal letrehozott **T** elemeket
	tartalmazo objektum legyen **kompatibilis** az std::vector sablonnal letrehozott **T** elemeket
	tartalmazo objektummal! Az std::vector sablon alapertelmezett sablonparameterei (pl.: allocator),
	hagyja alapertelmezettnek! Pelda az adapter hasznalatara:

	PyTomb<int> vi(3);	// vi 3 elemu int vektor
	vi[0] = 1; vi[1] = 2; vi[2] = 3;
	std::cout << vi[-1] << vi[-2] << vi[-3];	// KIIR: 321

	int t[] = { 1, 2, 3, 4, 5};
	PyTomb<int> vt(t, t+5);						// vt 5 elemu int vektor, ami t-bol inicializalt

	std::vector<int> v = vi;					// kompatibilitas miatt
	PyTomb<double> dd;							// dd 0 elemu double vektor
	dd.insert(dd.begin(), 3.14);
	std::cout << dd[0] << ' ' << dd[-1];		// KIIR: 3.14 3.14
	dd[-2];										// std::out_of_range kivetelt dob

	Emlekezteto: Az std::vector::at() indexhatar ellenorzest vegez. Hiba eseten std::out_of_range hibat dob

	**Ugyeljen** a sorozattarolokra jellemzo konstruktorok megvalositasara is! A std::vector azonos
	konstruktorainak megfeleloen adja meg ezeket ennel az osztalynal is:

	PyTomb(size_t, const T&) // konstruktor merettel es init ertekkel, alapertelmezett (default) parameterekkel
	PyTomb(first, last) // iteratorokkal megadott konstruktor

*/


//==============================================================================================================

#include <iostream>
#include <vector>

template<typename T>
struct PyTomb {
	std::vector<T> adat;
	PyTomb() = default;
	PyTomb(size_t n, const T& init = T()) {
		adat.resize(n);
	}

	PyTomb(T* first, T* last) {
		adat.resize(last - first);
		for (size_t i = 0; i < adat.size(); i++) {
			adat[i] = first[i];
		}
	}

	void insert(typename std::vector<T>::iterator hova, const T& n) {
		adat.insert(hova, n);
	}

	T& operator[](int i) {
		if (i < 0) i += adat.size();
		return adat.at(i); 
	}

	operator std::vector<T>() const {
		return adat;
	}

	typename std::vector<T>::iterator begin() { return adat.begin(); }
	typename std::vector<T>::iterator end() { return adat.end(); }
};
