#include <iostream>
#include <vector>
using namespace std;

double mean(const vector<int>& sequence) {
    double sum = 0;
    for (auto x : sequence) {
        sum += x;
    }
    return sum / sequence.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> days(n);
    for (int& day : days) {
        cin >> day;
    }

    auto avgTemp = mean(days);
    vector<int> moreThanAvg;

    for (int i = 0; i < days.size(); ++i) {
        if (days[i] > avgTemp) {
            moreThanAvg.push_back(i);
        }
    }

    cout << moreThanAvg.size() << endl;
    for (int dayIndex : moreThanAvg) {
        cout << dayIndex << ' ';
    }
    return(0);
}
