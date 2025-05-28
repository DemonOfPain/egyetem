#include <iostream>
#include <string>

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