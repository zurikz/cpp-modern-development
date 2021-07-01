#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct name {
    string first;
    string last;
};

string NameToReturn(const name& nameOfPerson) {
    if (nameOfPerson.first.empty()) {
        return nameOfPerson.last + " with unknown first name";
    } else if (nameOfPerson.last.empty()) {
        return nameOfPerson.first + " with unknown last name";
    } else {
        return nameOfPerson.first + " " + nameOfPerson.last;
    }
}

vector<int> GetYears(const map<int, name> mapping) {
    vector<int> years;
    for (const auto& [year, name] : mapping) {
        years.push_back(year);
    }
    return years;
}

class Person {
public:
    void ChangeFirstName(int yearOfChange, const string& firstName) {
        YearToName[yearOfChange].first = firstName;
    }
    void ChangeLastName(int yearOfChange, const string& lastName) {
        YearToName[yearOfChange].last = lastName;
    }
    string GetFullName(int yearToShow) {
        vector<int> years = GetYears(YearToName);
        name nameToShow;

        if (yearToShow < years[0]) {
            return "Incognito";
        } else {
            for (int i = years.size() - 1; i >= 0; --i) {
                if (years[i] <= yearToShow) {
                    if (nameToShow.first.empty())
                        nameToShow.first = YearToName[years[i]].first;
                    if (nameToShow.last.empty())
                        nameToShow.last = YearToName[years[i]].last;
                }
            }
            return NameToReturn(nameToShow);
        }
    }

private:
    map<int, name> YearToName;
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}
