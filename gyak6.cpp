template <typename Iter, class Pred>
int count_if(Iter eleje, Iter vege, Pred pred) {
    int n = 0;
    while (eleje != vege) {
        // n = pred(*eleje) ? n++ : n;
        if (pred(*eleje))
            n++;
        eleje++;
    }
    return n;
}

template <typename T>
class Ecet {
private:
    T n;

public:
    Ecet(T valami) : n(valami) {}
    bool operator()(const T &dolog) { return dolog < n; }
};