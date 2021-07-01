#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

class Date {
public:
    Date() {}

    Date(int newYear, int newMonth, int newDay) {
        if (newMonth < 1 || newMonth > 12) {
            throw invalid_argument("Month value is invalid: " + to_string(newMonth));
        }
        if (newDay < 1 || newDay > 31) {
            throw invalid_argument("Day value is invalid: " + to_string(newDay));
        }
        year = newYear;
        month = newMonth;
        day = newDay;
    }

    int GetYear() const {
        return year;
    }
    int GetMonth() const {
        return month;
    }
    int GetDay() const {
        return day;
    }

private:
    int year;
    int month;
    int day;
};

istream& operator>>(istream& istream1, Date& date) {
    string dateString;
    istream1 >> dateString;
    stringstream dateStream(dateString);

    bool ok = true;

    int year;
    ok = ok && (dateStream >> year);
    ok = ok && (dateStream.peek() == '-');
    dateStream.ignore(1);

    int month;
    ok = ok && (dateStream >> month);
    ok = ok && (dateStream.peek() == '-');
    dateStream.ignore(1);

    int day;
    ok = ok && (dateStream >> day);
    ok = ok && dateStream.eof();

    if (!ok) {
        throw invalid_argument("Wrong date format: " + dateString);
    }
    date = Date(year, month, day);
    return istream1;
}

ostream& operator<<(ostream& ostream1, const Date& date) {
    ostream1 << setw(4) << setfill('0') << date.GetYear() << '-'
             << setw(2) << setfill('0') << date.GetMonth() << '-'
             << setw(2) << setfill('0') << date.GetDay();
    return ostream1;
}

bool operator<(const Date& left, const Date& right) {
    return vector<int>{left.GetYear(), left.GetMonth(), left.GetDay()} <
           vector<int>{right.GetYear(), right.GetMonth(), right.GetDay()};
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        dateToEvents[date].insert(event);
    }

    bool DeleteEvent(const Date& date, const string& event) {
        if (dateToEvents.count(date) > 0 && dateToEvents[date].count(event) > 0) {
            dateToEvents[date].erase(event);
            return true;
        }
        return false;
    }

    int  DeleteDate(const Date& date) {
        if (dateToEvents.count(date) == 0) {
            return 0;
        } else {
            const int numOfDeletedEvents = dateToEvents[date].size();
            dateToEvents.erase(date);
            return numOfDeletedEvents;
        }
    }

    set<string> Find(const Date& date) const {
        if (dateToEvents.count(date) > 0) {
            return dateToEvents.at(date);
        } else {
            return {};
        }
    }
  
    void Print() const {
        for (const auto& [date, events] : dateToEvents) {
            for (const auto& event : events) {
                cout << date << ' ' << event << endl;
            }
        }
    }

private:
    map<Date, set<string>> dateToEvents;
};

int main() {
    Database db;

    string request;
    while (getline(cin, request)) {
        stringstream requestStream(request);

        string command;
        requestStream >> command;

        try {

            if (command == "Print") {

                db.Print();

            } else if (command == "Find") {

                Date dateToFind;
                requestStream >> dateToFind;
                for (const auto& event : db.Find(dateToFind)) {
                    cout << event << endl;
                }

            } else if (command == "Del") {

                Date dateToDel;
                requestStream >> dateToDel;

                if (requestStream.eof()) {
                    cout << "Deleted " << db.DeleteDate(dateToDel)
                         << " events" << endl;
                } else {
                    string event;
                    requestStream >> event;
                    if (db.DeleteEvent(dateToDel, event)) {
                        cout << "Deleted successfully" << endl;
                    } else {
                        cout << "Event not found" << endl;
                    }
                }

            } else if (command == "Add") {

                Date dateToAdd;
                requestStream >> dateToAdd;
                string eventToAdd;
                requestStream >> eventToAdd;

                db.AddEvent(dateToAdd, eventToAdd);

            } else {

                if (command != "") {
                    throw invalid_argument("Unknown command: " + command);
                }

            }

        } catch (invalid_argument& error) {
            cout << error.what() << endl;
        }

    }

    return 0;
}
