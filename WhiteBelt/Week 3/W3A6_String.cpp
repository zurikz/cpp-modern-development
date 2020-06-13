#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class ReversibleString {
public:
    ReversibleString() {}
    ReversibleString(const string& input) {
        line = input;
    }
    void Reverse() {
        reverse(begin(line), end(line));
    }
    string ToString() const {
        return line;
    }
private:
    string line;
};

int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}
