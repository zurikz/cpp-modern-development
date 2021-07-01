#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
    string name;
    string surname;
    int birthDay;
    int birthMonth;
    int birthYear;
};

string DoRequest(const vector<Student>& data,
                 const string& request,
                 const int& index) {
    if (request == "name") {
        return data[index].name + " " + data[index].surname;
    } else if (request == "date") {
        return to_string(data[index].birthDay) + "."
         + to_string(data[index].birthMonth) + "."
         + to_string(data[index].birthYear);
    } else {
        return "bad request";
    }
}

int main() {
    int numOfStudents;
    cin >> numOfStudents;

    vector<Student> students(numOfStudents);

    for (auto& student : students) {
        cin >> student.name >> student.surname
            >> student.birthDay >> student.birthMonth
            >> student.birthYear;
    }

    int numOfRequests;
    cin >> numOfRequests;

    for (int i = 0; i < numOfRequests; ++i) {
        string request;
        int indexOfStudent;
        cin >> request >> indexOfStudent;

        if (indexOfStudent < 1 || numOfStudents < indexOfStudent) {
            cout << "bad request" << endl;
        } else {
            --indexOfStudent;
            cout << DoRequest(students, request, indexOfStudent)
                 << endl;
        }
    }

    return 0;
}
