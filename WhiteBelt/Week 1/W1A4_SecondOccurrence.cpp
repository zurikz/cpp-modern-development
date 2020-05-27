#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    int index = -1;
    int occurrences = 0;
    cin >> str;

    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == 'f') {
            ++occurrences;
            if (occurrences == 2)
                index = i;
        }
    }

    if (occurrences >= 2) {
        cout << index;
    } else if (occurrences == 1) {
        cout << -1;
    } else {
        cout << -2;
    }

    return(0);
}
