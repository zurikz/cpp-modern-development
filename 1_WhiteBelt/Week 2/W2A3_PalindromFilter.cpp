#include <vector>
#include <string>
using namespace std;

bool IsPalindrom(string str) {
    for (int i = 0; i <= (str.size() / 2); ++i) {
        if (str[i] != str[str.size() - (i + 1)]) {
            return false;
        }
    }
    return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> palindroms;
    for (auto word : words) {
        if (word.size() >= minLength && IsPalindrom(word)) {
            palindroms.push_back(word);
        }
    }
    return palindroms;
}

int main() {
    return(0);
}
