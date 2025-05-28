template <typename T, typename S = std::vector>
class ModuloTomb : public S {
private:
    S<T> adat;

    T &operator[](const size_t i);
    T operator[](const size_t i) const;

public:
    ModuloTomb(size_t i = 0, const T &value = T()) : S(i, value) {}
    template <typename Iter>
    ModuloTomb(Iter eleje, Iter vege) : S(eleje, vege) {}

    T &at(int i) {
        return S::at(i % adat.size());
    }

    const T &at(int i) const {
        return S::at(i % adat.size());
    }
}

template <typename Iter>
bool monotonNovekvo(Iter eleje, Iter vege) {
    if (eleje == vege)
        return true;
    while (eleje + 1 != vege) {
        if (*eleje >= *(eleje + 1))
            return false;
        eleje++;
    }
    return true;
}