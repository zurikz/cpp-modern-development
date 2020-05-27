#include <iostream>
using namespace std;

int main() {
    double price, bound1, bound2;
    double discount1, discount2;
    cin >> price >> bound1 >> bound2 >> discount1 >> discount2;

    if (bound2 < price) {
        price -= (discount2 / 100) * price;
    } else if (bound1 < price) {
        price -= (discount1 / 100) * price;
    }

    cout << price;
    return 0;
}
