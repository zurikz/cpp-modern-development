#include <iostream>
#include <map>
#include <string>
using namespace std;

map<char, int> BuildCharCounters(const string& word) {
    map<char, int> result;
    for (const auto& letter : word) {
        ++result[letter];
    }
    return result;
}

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        string first, second;
        cin >> first >> second;
        if (BuildCharCounters(first) == BuildCharCounters(second)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}