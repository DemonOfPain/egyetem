#ifndef HETERO_STORE_HPP
#define HETERO_STORE_HPP

#include <cstddef>
#include <stdexcept>

/**
 * HeteroStore - Heterogén kollekciók tárolására szolgáló sablon osztály
 * @tparam Base - Az alaposztály típusa
 * @tparam Size - A belső tároló mérete (alapértelmezetten 100)
 * @tparam ExceptionType - Kivétel osztály, amit hiba esetén eldob (alapértelmezetten std::out_of_range)
 */
template <typename Base, size_t Size = 100, typename ExceptionType = std::out_of_range>
class HeteroStore {
private:
    Base *store[Size]; // Fix méretű tároló a pointereknek
    size_t count;      // Ténylegesen tárolt pointerek száma

public:
    /**
     * Konstruktor
     */
    HeteroStore() : count(0) {}

    /**
     * Destruktor - Felszabadítja a tárolt objektumokat
     */
    ~HeteroStore() {
        clear();
    }

    /**
     * Másoló konstruktor letiltása - privát és nincs implementálva
     */
    HeteroStore(const HeteroStore &);

    /**
     * Értékadás operátor letiltása - privát és nincs implementálva
     */
    HeteroStore &operator=(const HeteroStore &);

    /**
     * Visszaadja a tárolt pointerek számát
     * @return A tárolt pointerek száma
     */
    size_t size() const {
        return count;
    }

    /**
     * Visszaadja a tároló maximális méretét
     * @return A tároló maximális mérete
     */
    size_t capacity() const {
        return Size;
    }

    /**
     * Beteszi a tárolóba a paraméterként kapott pointert
     * @param p - A tárolóba helyezendő pointer
     * @throws ExceptionType - Ha a tároló megtelt
     */
    void add(Base *p) {
        if (count >= Size) {
#ifdef delete
            ::delete p; // Felszabadítjuk a pointert, mert a tároló felelős érte
#else
            delete p; // Felszabadítjuk a pointert, mert a tároló felelős érte
#endif
            throw ExceptionType("A tároló megtelt");
        }
        store[count++] = p;
    }

    /**
     * A tároló minden elemével meghívja a paraméterként kapott funktort
     * @tparam Functor - A funktor típusa
     * @param func - A meghívandó funktor
     */
    template <typename Functor>
    void traverse(Functor func) {
        for (size_t i = 0; i < count; ++i) {
            func(store[i]);
        }
    }

    /**
     * Törli és felszabadítja a tárolóban tárolt objektumokat
     */
    void clear() {
        for (size_t i = 0; i < count; ++i) {
#ifdef delete
            ::delete store[i];
#else
            delete store[i];
#endif
            store[i] = nullptr;
        }
        count = 0;
    }
};

#endif // HETERO_STORE_HPP