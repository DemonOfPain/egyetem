#pragma once
/*
	Egyes programozási nyelvekben a tömbök indexhatárai is megadhatók deklarációjukkor. Így pl. lehet olyan tömböt létrehozni, ami -3-tól +5-
ig indexelhetõ.
Készítsen adapter sablont (ArrayLB) az std::vector tárolóhoz, ami lehetõvé teszi, hogy ne csak 0-tól indexelhetõ vektorokat hozzunk létre. A
sablon elsõ paramétere az adattípus, a második pedig egy int (N), ami az alsó indexhatár. Alapértelmezésként N = 0 legyen! A sablon csak
az indexelés mûveletét alakítsa át! A többi publikus mûveletet (konstruktorokat is) változtatás nélkül tegye elérhetõvé!
Az ArrayLB sablonnal létrehozott T elemeket tartalmazó objektum legyen kompatibilis az std::vector sablonnal létrehozott T elemeket
tartalmazó objektummal! Elegendõ az indexelõ operátorokat (operator[]) megvalósítania, az at() helyes mûködését nem vizsgáljuk! Példa az
adapter használatára:

ArrayLB<int, -1> vi(3);			// vi 3 elemû int vektor, ami -1..+1 között indexelhetõ
vi[-1] = 12;
vi.push_back(15);				// std::vector minden tagfüggvénye elérhetõ

int t[] = { 1, 2, 3, 4, 5 };
ArrayLB<int, -5> vt(t, t + 5);	// vt 5 elemû int vektor, ami -5..-1 között indexelhetõ, és
								// t-bõl inicializált (1,2,3,4,5 elemekkel)

std::vector<int> v = vi;		// kompatibilitás miatt
ArrayLB<double, 10> dd;			// dd 0 elemû double vektor
dd.insert(dd.begin(), 3.14);	//
std::cout << dd[10];			// KIIR 3.14

	Ügyeljen a sorozattárolókra jellemzõ konstruktorok megvalósítására is!Az std::vector 
	sablon alapértelmezett sablonparamétereit(pl.allocator), hagyja alapértelmezettnek!
*/

//==============================================================================================================

