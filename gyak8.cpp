#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::vector<T> indexgen(T also, T felso) {
    std::vector<T> tomb(felso - also);
    std::generate(tomb.begin(), tomb.end(), [&also]() { return also++; });
    return tomb;
}

//---------------

template <typename T, size_t Cap = 10>
class MySet {
private:
    T elements[Cap];
    size_t meret = 0;

public:
    const bool contains(const T &elem) {
        for (size_t i = 0; i < meret; i++) {
            if (elem == elements[i])
                return true;
        }
        return false;
    }

    void insert(const T &elem) {
        if (this->contains(elem))
            return;
        if (meret == Cap)
            throw "HIBA";
        elements[meret] = elem;
        meret++;
    }

    const size_t size() {
        return meret;
    }

    const size_t capacity() {
        return Cap;
    }
};

//---------------

class Complex {
protected:
    float r, i;

public:
    Complex(float r, float i);
    float getR() const;
    float getI() const;
};

struct Serializable {
    virtual void write(std::ostream &os) const = 0;
    virtual void read(std::istream &is) = 0;
};

class SComplex : public Complex, public Serializable {
public:
    SComplex(float r, float i) : Complex(r, i) {}
    void write(std::ostream &os) const override {
        os << "SComplex " << r << "+" << i << "j\n";
    }

    void read(std::istream &is) override {
        std::string s, p, j;
        float u_r, u_i;

        is >> s >> u_r >> p >> u_i >> j;

        if (s != "SComplex" || p != "+" || j != "j") {
            throw "wrong";
        }

        this->r = u_r;
        this->i = u_i;
    }
};

//---------------

template <typename T>
class PyTomb : public std::vector<T> {

public:
    PyTomb() : std::vector<T>() {}
    PyTomb(size_t size, const T &value = T()) : std::vector<T>(size, value) {}
    template <typename Iter>
    PyTomb(Iter eleje, Iter vege) : std::vector<T>(eleje, vege) {}

    T &operator[](int i) {
        return i >= 0 ? this->at(i) : this->at(this->size() + i);
    }
};

//---------------

main() {
    PyTomb<int> vi(3);
    vi[0] = 1;
    vi[1] = 2;
    vi[2] = 3;
    std::cout << vi[-1] << vi[-2] << vi[-3];

    int t[] = {1, 2, 3, 4, 5};
    PyTomb<int> vt(t, t + 5);

    std::vector<int> v = vi;
    PyTomb<double> dd;
    dd.insert(dd.begin(), 3.14);
    std::cout << dd[0] << " " << dd[-1];

    return 0;
}