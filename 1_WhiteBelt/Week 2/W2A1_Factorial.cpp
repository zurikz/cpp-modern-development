#include <iostream>
using namespace std;

int Factorial(int x) {
    if (x <= 1) {
        return 1;
    } else {
        return x * Factorial(x - 1);
    }
}

int main() {
    int n;
    cin >> n;
    cout << Factorial(n);
    return(0);
}