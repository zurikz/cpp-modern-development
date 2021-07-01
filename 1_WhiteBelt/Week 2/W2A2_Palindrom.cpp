#include <iostream>
#include <string>
using namespace std;

bool IsPalindrom(string str) {
    for (int i = 0; i < (str.size() / 2); ++i) {
        if (str[i] != str[str.size() - (i + 1)]) {
            return false;
        }
    }
    return true;
}

int main() {
    string input;
    cin >> input;
    cout << boolalpha << IsPalindrom(input);
    return(0);
}