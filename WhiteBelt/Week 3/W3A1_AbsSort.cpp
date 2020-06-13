#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int& num : numbers) {
        cin >> num;
    }

    sort(begin(numbers), end(numbers),
            [](int x, int y) { return abs(x) < abs(y); });
    for (const auto& num : numbers) {
        cout << num << " ";
    }

    return 0;
}