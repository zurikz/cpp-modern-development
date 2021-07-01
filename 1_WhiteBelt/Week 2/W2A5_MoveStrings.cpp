void MoveStrings(vector<string>& source, vector<string>& destination) {
    for (auto word : source) {
        destination.push_back(word);
    }
    source.clear();
}