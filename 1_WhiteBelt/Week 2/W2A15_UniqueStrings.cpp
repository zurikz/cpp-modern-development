#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;

    set<string> lines;

    for (int i = 0; i < n; ++i) {
        string line;
        cin >> line;
        lines.insert(line);
    }

    cout << lines.size();
    return 0;
}
