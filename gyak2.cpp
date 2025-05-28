#include <algorithm>
#include <iostream>
#include <vector>

bool paros(int x) {
    return x % 2 == 0 ? true : false;
}

std::vector<bool> boolindexing(const std::vector<int> &t, bool (*pred)(int)) {
    std::vector<bool> bt(t.size());
    std::transform(t.begin(), t.end(), bt.begin(), pred);
    return bt;
}

int main() {
    std::vector<int> t = {0, 1, 2, 3, 4, 5, 6, 10, 111};
    std::vector<bool> tb = boolindexing(t, paros);
    for (bool k : tb) {
        std::cout << k << ',';
    }

    return 0;
}
