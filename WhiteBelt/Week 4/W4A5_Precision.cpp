#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    ifstream input("input.txt");
    double number;

    cout << fixed << setprecision(3);

    if (input) {
        while (input >> number) {
            cout << number << endl;
        }
    } else {
        cout << "Error!";
    }

    return 0;
}
