#pragma once

/*
	Keszitsen egy olyan fuggvenyt (indexgen neven), ami ket parametert kap: Egy kezdo szamerteket (int), valamint egy felso hatart (int). 
	A fuggveny feladata egy olyan tomb (std::vector<int>) visszaadas, ami az osszes egesz szamot tartalmazza a kezdo szamtol (also hatar) 
	a felso hatarig (azt mar nem). A fuggveny fejlecet magadtuk, azt ne valtoztssa! 

	Hasznalja fel ehhez az std::generate fuggvenyt! For vagy while ciklust ne hasznaljon! 
	A megoldashoz tovabbi segedfuggvenyt, osztaly is felvehet!

	Csak szintaktikai hibaktol mentes kod fogadhato el!

	Pelda a hasznalatra:

	std::vector<int> t = indexgen(0,4);
	for(int k : t)
		std::cout << k << ','; // 0,1,2,3
*/

//==============================================================================================================

#include <vector>
#include <iostream>
#include <algorithm> // a generatehez szukseges

// Funktor (valszeg funktort varnak el, de lambdaval is meg lehetne oldani)
class Gen {
	int i; // r
public:
	Gen(int start) : i(start) {} // konstruktor
	int operator()() { return i++; } // hivhato lesz
};

std::vector<int> indexgen(int also, int felso) {
	std::vector<int> v(felso-also);
	Gen gen(also); 
	std::generate(v.begin(), v.end(), gen);
	return v;
}