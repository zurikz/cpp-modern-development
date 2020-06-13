#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct NameAndHistory {
    string name;
    vector<string> history;
};

string PrintHistory(const vector<string>& history) {
    if (history.empty()) {
        return "";
    }

    string output = " (";
    for (const auto& name : history) {
        output += name + ", ";
    }
    output.resize(output.size() - 2);
    return output + ")";
}

NameAndHistory FindNameAndHistoryByYear(
        const map<int, string>& names, int yearToFind) {
    string nameToFind;
    vector<string> history;

    for (const auto& [year, name] : names) {
        if (year <= yearToFind) {
            nameToFind = name;
            history.push_back(name);
        }
        else
            break;
    }

    reverse(begin(history), end(history));

    for (int i = 0; i < history.size(); ++i) {
        if (history[i] == history[i + 1] || (i == 0 && nameToFind == history[i])) {
            history.erase(begin(history) + i);
            --i;
        }
    }

    return {nameToFind, history};
}

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        first_names[year] = first_name;
    }

    void ChangeLastName(int year, const string& last_name) {
        last_names[year] = last_name;
    }

    string GetFullName(int year) {
        const string firstName = FindNameAndHistoryByYear(first_names, year).name;
        const string lastName = FindNameAndHistoryByYear(last_names, year).name;

        if (firstName.empty() && lastName.empty()) {
            return "Incognito";
        } else if (firstName.empty()) {
            return lastName + " with unknown first name";

        } else if (lastName.empty()) {
            return firstName + " with unknown last name";

        } else {
            return firstName + " " + lastName;
        }
    }

    string GetFullNameWithHistory(int year) {
        const NameAndHistory firstNameAndHistory = FindNameAndHistoryByYear(first_names, year);
        const NameAndHistory lastNameAndHistory = FindNameAndHistoryByYear(last_names, year);

        if (firstNameAndHistory.name.empty() && lastNameAndHistory.name.empty()) {
            return "Incognito";
        } else if (firstNameAndHistory.name.empty()) {
            return lastNameAndHistory.name + PrintHistory(lastNameAndHistory.history)
                                            + " with unknown first name";

        } else if (lastNameAndHistory.name.empty()) {
            return firstNameAndHistory.name + PrintHistory(firstNameAndHistory.history)
                   + " with unknown last name";

        } else {
            return firstNameAndHistory.name + PrintHistory(firstNameAndHistory.history)
                        + " " + lastNameAndHistory.name + PrintHistory(lastNameAndHistory.history);
        }

    }

private:
    map<int, string> first_names;
    map<int, string> last_names;
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}
