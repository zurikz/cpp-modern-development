#include <iostream>

using namespace std;

int main() {
    int n, r;
    uint64_t w, h, d;
    uint64_t mass = 0;

    cin >> n >> r;
    for (int i = 0; i < n; ++i) {
        cin >> w >> h >> d;
        uint64_t volume = w * h * d;
        mass += volume * r;
    }

    cout << mass;
    return 0;
}