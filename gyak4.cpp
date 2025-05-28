#include <iostream>

class LinCon {
protected:
    int a, b, m;

public:
    LinCon(int a, int b, int m);
    int GetA() const;
    int GetB() const;
    int GetM() const;
};

struct Serializable {
    virtual void write(std::ostream &os) const = 0;
    virtual void read(std::istream &is) = 0;
};

class SLinCon : public LinCon, public Serializable {
public:
    SLinCon(int a, int b, int m) : LinCon(a, b, m) {}

    void write(std::ostream &os) const {
        os << a << "x=" << b << " |" << m;
    }

    void read(std::istream &is) {
        int u_a, u_b, u_m;
        char x, e, v;

        is >> u_a >> x >> e >> u_b >> v >> u_m;

        if (x != 'x' || e != '=' || v != '|') {
            throw "hiba";
        }

        a = u_a;
        b = u_b;
        m = u_m;
    }
};
