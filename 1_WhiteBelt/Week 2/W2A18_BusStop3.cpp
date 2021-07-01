#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

int main() {
    int q;
    cin >> q;

    map<set<string>, int> stopsToNumber;

    for (int i = 0; i < q; ++i) {

        int stopCount;
        cin >> stopCount;

        set<string> stops;

        for (int j = 0; j < stopCount; ++j) {
            string stop;
            cin >> stop;
            stops.insert(stop);
        }

        if (stopsToNumber.count(stops) == 1) {
            cout << "Already exists for " << stopsToNumber[stops]
                 << endl;
        } else {
            int currentSize = stopsToNumber.size();
            stopsToNumber[stops] = currentSize + 1;
            cout << "New bus " << currentSize + 1 << endl;
        }

    }
    return 0;
}
