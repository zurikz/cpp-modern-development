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
        if (history[i] == history[i + 1] ||
           (i == 0 && nameToFind == history[i])) {
            history.erase(begin(history) + i);
            --i;
        }
    }

    return {nameToFind, history};
}

class Person {
public:
    Person(const string& firstName, const string& lastName, int yearOfBirth) {
        first_names[yearOfBirth] = firstName;
        last_names[yearOfBirth] = lastName;
        dateOfBirth = yearOfBirth;
    }

    void ChangeFirstName(int year, const string& first_name) {
        if (dateOfBirth <= year) {
            first_names[year] = first_name;
        }
    }

    void ChangeLastName(int year, const string& last_name) {
        if (dateOfBirth <= year) {
            last_names[year] = last_name;
        }
    }

    string GetFullName(int year) const {
        const string firstName = FindNameAndHistoryByYear(first_names, year).name;
        const string lastName = FindNameAndHistoryByYear(last_names, year).name;

        if (year < dateOfBirth) {
            return "No person";
        } else if (firstName.empty() && lastName.empty()) {
            return "Incognito";
        } else if (firstName.empty()) {
            return lastName + " with unknown first name";

        } else if (lastName.empty()) {
            return firstName + " with unknown last name";

        } else {
            return firstName + " " + lastName;
        }
    }

    string GetFullNameWithHistory(int year) const {
        const NameAndHistory firstNameAndHistory = FindNameAndHistoryByYear(first_names, year);
        const NameAndHistory lastNameAndHistory = FindNameAndHistoryByYear(last_names, year);

        if (year < dateOfBirth) {
            return "No person";
        } else if (firstNameAndHistory.name.empty() && lastNameAndHistory.name.empty()) {
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
    int dateOfBirth;
};

int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}
