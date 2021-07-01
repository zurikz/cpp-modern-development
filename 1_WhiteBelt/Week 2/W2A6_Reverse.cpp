#include <iostream>
#include <vector>
using namespace std;

void Reverse(vector<int>& numbers) {
    for (int i = 0; i < (numbers.size() / 2); ++i) {
        int temp = numbers[numbers.size() - (i + 1)];
        numbers[numbers.size() - (i + 1)] = numbers[i];
        numbers[i] = temp;
    }
}

int main() {
    vector<int> numbers = {1, 2, 4, 5, 6};
    Reverse(numbers);
    for (auto num : numbers) {
        cout << num << " ";
    }
    return(0);
}