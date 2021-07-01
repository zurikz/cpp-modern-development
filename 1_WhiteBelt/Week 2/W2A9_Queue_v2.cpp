#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int q;
    cin >> q;
    vector<bool> isNervous;

    for (int i = 0; i < q; ++i) {
        string operation;
        cin >> operation;

        if (operation == "WORRY_COUNT") {
            cout << count(begin(isNervous), end(isNervous), true) << endl;
        } else {
            if (operation == "WORRY" || operation == "QUIET") {
                int personIndex;
                cin >> personIndex;

                isNervous[personIndex] = (operation == "WORRY");

            } else if (operation == "COME") {
                int personCount;
                cin >> personCount;

                isNervous.resize(isNervous.size() + personCount, false);

            }
        }
    }

    return 0;
}