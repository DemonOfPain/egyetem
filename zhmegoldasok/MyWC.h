#pragma once
/// Ez IMSC feladat volt

/*
	Adapter a következõ sablon, ami különbözõ értékek (VAL) elõfordulási számának meghatározására alkalmas:
*/

template<typename VAL>
class Counter {
    std::map<VAL, size_t> values;
public:
    virtual void reset() {
        values.clear();
    }

    virtual void count(const VAL& key) {
        values[key]++;
    }

    virtual size_t get(const VAL& key) const {
        return values.at(key); // hiba esetén std::out_of_range exp-et dob
    }
};

/*

    A sablon felhasználásával hozzon létre egy MyWC osztályt, amely szavak (std::string) számlálására 
    alkalmas. Az osztály konstruktorában legyen megadható egy bool érték, hogy a kis- és nagybetûket 
    azonosnak, vagy különbözõnek tekintse-e az osztály. A megoldás során célszerû felhasználnia a 
    globális std::string to_lower(std::string) függvényt. Az alábbi példa az osztály használatát demonstrálja:

    MyWC wc(true); // az osztály érzékeny a kis/nagy betûkre
    wc.count("alma"); // különbözõ elemeknek minõsülnek
    wc.count("ALMA");
    wc.count("ALMA");
    std::cout << wc.get("alma") << std::endl; // 1
    std::cout << wc.get("ALMA") << std::endl; // 2

    És hogyha nem:

    MyWC wc(false); // az osztály NEM érzékeny a kis/nagy betûkre
    wc.count("alma"); // azonos elemeknek minõsülnek
    wc.count("ALMA");
    wc.count("ALMA");
    std::cout << wc.get("alma") << std::endl; // 3
    std::cout << wc.get("ALMA") << std::endl; // 3 (ugyanazok)

    Az osztályt lássa el indexelõ operátorral is, amivel lekérdezhetõ hogy az egyes szavakból, 
    mennyi van, hasonlóan a get() függvényhez, viszont ha egy olyan szót kap paraméterként, 
    ami még nincs, akkor ne dobjon kivételt, hanem térjen vissza 0-val!
*/

//==============================================================================================================
