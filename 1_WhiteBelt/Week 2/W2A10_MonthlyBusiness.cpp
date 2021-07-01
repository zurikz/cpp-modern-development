#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    const vector<int> daysInMonth =
            {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    vector<vector<string>> activities(31);
    int currentMonth = 0;

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        string operation;
        cin >> operation;

        int nextMonth = (currentMonth + 1) % 12;

        if (operation == "NEXT") {
            if (daysInMonth[currentMonth] > daysInMonth[nextMonth]) {
                int lastDay = daysInMonth[nextMonth] - 1;

                for (int extraDay = lastDay + 1; extraDay < daysInMonth[currentMonth]; ++extraDay) {
                    activities[lastDay].insert(end(activities[lastDay]),
                                               begin(activities[extraDay]),
                                               end(activities[extraDay]));
                }
            }

            activities.resize(daysInMonth[nextMonth]);
            currentMonth = nextMonth;

        } else {
            int day;
            cin >> day;
            --day;

            if (operation == "ADD") {
                string activity;
                cin >> activity;
                activities[day].push_back(activity);
            }

            if (operation == "DUMP") {
                cout << activities[day].size() << " ";
                for (const auto& activity : activities[day]) {
                    cout << activity << " ";
                }
            cout << endl;
            }
        }
    }
    return 0;
}
