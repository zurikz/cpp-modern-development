#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string strToLower(string& line) {
    for (auto& symbol : line) {
        symbol = tolower(symbol);
    }
    return line;
}

int main() {
    int n;
    cin >> n;

    vector<string> lines(n);
    for (string& line : lines) {
        cin >> line;
    }

    sort(begin(lines), end(lines),
            [](string x, string y)
            { return strToLower(x) < strToLower(y); });

    for (const auto& line : lines) {
        cout << line << " ";
    }
    return 0;
}
