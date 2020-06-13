#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        strings.push_back(s);
    }
    vector<string> GetSortedStrings() {
        sort(begin(strings), end(strings));
        return strings;
    }
private:
    vector<string> strings;
};

int main() {
    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");

    for (const auto& str : strings.GetSortedStrings()) {
        cout << str << " ";
    }
    cout << endl;

    strings.AddString("second");

    for (const auto& str : strings.GetSortedStrings()) {
        cout << str << " ";
    }

    return 0;
}