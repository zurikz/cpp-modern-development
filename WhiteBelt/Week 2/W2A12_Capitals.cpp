#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int q;
    cin >> q;

    map<string, string> capitals;

    for (int i = 0; i < q; ++i) {
        string operation;
        cin >> operation;

        if (operation == "DUMP") {

            if (capitals.empty()) {
                cout << "There are no countries in the world" << endl;
            } else {
                for (const auto& [key, value] : capitals) {
                    cout << key << "/" << value << " ";
                }
                cout << endl;
            }

        } else if (operation == "ABOUT") {

            string country;
            cin >> country;

            if (capitals.count(country) == 0) {
                cout << "Country " << country << " doesn't exist" << endl;
            } else {
                cout << "Country " << country << " has capital "
                                              << capitals[country] << endl;
            }

        } else if (operation == "RENAME") {

            string oldCountry, newCountry;
            cin >> oldCountry >> newCountry;

            if ((oldCountry == newCountry) || (capitals.count(oldCountry) == 0)
                                           || (capitals.count(newCountry) == 1)) {
                cout << "Incorrect rename, skip" << endl;
            } else {
                cout << "Country " << oldCountry << " with capital "
                     << capitals[oldCountry] << " has been renamed to "
                     << newCountry << endl;

                capitals[newCountry] = capitals[oldCountry];
                capitals.erase(oldCountry);
            }

        } else if (operation == "CHANGE_CAPITAL") {

            string country, newCapital;
            cin >> country >> newCapital;

            if (capitals[country].empty()) {
                capitals[country] = newCapital;
                cout << "Introduce new country " << country << " with capital "
                                                 << newCapital << endl;
            } else if (capitals[country] == newCapital) {
                cout << "Country " << country << " hasn't changed its capital" << endl;
            } else {
                cout << "Country " << country << " has changed its capital from "
                     << capitals[country] << " to " << newCapital << endl;
                capitals[country] = newCapital;
            }
        }
    }
    return 0;
}
