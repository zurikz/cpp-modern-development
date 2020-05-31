#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    int q;
    cin >> q;

    map<string, vector<string>> buses;
    map<string, vector<string>> stops;

    for (int i = 0; i < q; ++i) {
        string operation;
        cin >> operation;

        if (operation == "ALL_BUSES") {

            if (buses.empty()) {
                cout << "No buses" << endl;
            } else {
                for (const auto& [bus, stops] : buses) {
                    cout << "Bus " << bus << ": ";
                    for (const auto& stop : stops)
                        cout << stop << " ";
                    cout << endl;
                }
            }

        } else if (operation == "BUSES_FOR_STOP") {

            string stopToShow;
            cin >> stopToShow;

            if (stops.count(stopToShow) == 0) {
                cout << "No stop" << endl;
            } else {
                for (const auto& bus : stops[stopToShow]) {
                            cout << bus << " ";
                }
                cout << endl;
            }

        } else if (operation == "STOPS_FOR_BUS") {

            string busToShow;
            cin >> busToShow;

            if (buses.count(busToShow) == 0) {
                cout << "No bus" << endl;
            } else {
                for (const auto& stop : buses[busToShow]) {
                    cout << "Stop " << stop << ": ";
                    if (stops[stop].size() == 1) {
                        cout << "no interchange";
                    } else {
                        for (const auto& bus : stops[stop]) {
                            if (bus != busToShow)
                                cout << bus << " ";
                        }
                    }
                    cout << endl;
                }
            }

        } else if (operation == "NEW_BUS") {

            string bus;
            cin >> bus;
            int stopCount;
            cin >> stopCount;

            for (int j = 0; j < stopCount; ++j) {
                string stop;
                cin >> stop;
                buses[bus].push_back(stop);
                stops[stop].push_back(bus);
            }

        }
    }
    return 0;
}
