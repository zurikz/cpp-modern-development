#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> daysTemp(n);
    for (int& t : daysTemp) {
        cin >> t;
    }

    int64_t sum = 0;
    for (const int& t: daysTemp) {
        sum += t;
    }
    int mean = sum / n;

    vector<int> aboveAvgIndices;
    for (size_t i = 0; i < daysTemp.size(); ++i) {
        if (daysTemp[i] > mean) {
            aboveAvgIndices.push_back(i);
        }
    }

    cout << aboveAvgIndices.size() << endl;
    for (const auto& idx : aboveAvgIndices) {
        cout << idx << " ";
    }
    return 0;
}