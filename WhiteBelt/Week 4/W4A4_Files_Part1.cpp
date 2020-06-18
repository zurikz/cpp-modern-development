#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ifstream input("input.txt");
    string line;

    if (input.is_open()) {
        while (getline(input, line)) {
            cout << line << endl;
        }
    } else {
        cout << "Error!" << endl;
    }

    return 0;
}
