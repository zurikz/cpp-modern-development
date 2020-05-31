vector<int> Reversed(const vector<int>& numbers) {
    vector<int> reversed;
    for (int i = numbers.size() - 1; i >= 0; --i) {
        reversed.push_back(numbers[i]);
    }
    return reversed;
}