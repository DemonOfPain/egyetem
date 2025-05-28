#include <iostream>

template <typename T, size_t M = 3>
class GMtx {
private:
    size_t m;
    T adat[M][M];

public:
    GMtx(T elem) : m(M) {
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < m; j++) {
                adat[i][j] = elem;
            }
        }
    }

    T *operator[](const size_t idx) {
        return adat[idx];
    }
    const T *operator[](const size_t idx) const {
        return const adat[idx];
    }

    GMtx &operator+(const GMtx &mtx) {
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < m; j++) {
                this->adat[i][j] += mtx.adat[i][j];
            }
        }
        return *this;
    }
};