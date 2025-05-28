/*	
									!!! DISCLAIMER !!! 
 
	A file a 2024-es zh coderunner feladatait tartalmazza.

	A feladatok leiras es megoldasa az xyz.h fajlban talalhato, a kodot a vonal ala kell 
	megirni (jelenleg ott a sajat megoldasom van). [Megjegyzes: az xyz.h-ba ird a megoldast,
	mert az xyz.cpp fajlban a teszt futtatasahoz valo kiegeszitesek talahatoak]

	A feladatokhoz megprobaltam gtest-ben teszteket csinalni, ezek (hasonloan a megoldasaimhoz)
	nem feltetlen jok.

	A megfelelo teszt futtatasat a TESZT makroval lehet vezerelni.

*/


#include "PyTomb.hpp"
#include "SComplex.hpp"
#include "MySet.hpp"
#include "indexgen.hpp"
#include "Store.hpp"
#include "Store2.hpp"
#include "MyWC.hpp"
#include "ArrayLB.hpp"

#define TESZT 0

int main() {
#if TESZT == 1
	PyTombTest::runTest();
#endif 

#if TESZT == 2
	SComplexTest::runTest();
#endif 

#if TESZT == 3
	MySetTest::runTest();
#endif

#if TESZT == 4
	// meg nincs hozza teszt
	IndexgenTest::runTest();
#endif

#if TESZT == 5
	// meg nincs hozza teszt
	StoreTest::runTest();
#endif

#if TESZT == 6
	// meg nincs hozza teszt
	StoreTest2::runTest();
#endif

#if TESZT == 7
	// meg nincs hozza teszt
	MyWCTest::runTest();
#endif

#if TESZT == 8
	// meg nincs hozza teszt
	ArrayLBTest::runTest();
#endif


}

/// https://youtu.be/uyuVH3J3tdQ?si=SZroIcetqnJP1qJW