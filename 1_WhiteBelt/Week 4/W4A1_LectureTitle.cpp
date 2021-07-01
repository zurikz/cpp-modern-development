#include <string>
using namespace std;

struct Specialization {
    string name;
    explicit Specialization(const string& str) {
        name = str;
    }
};

struct Course {
    string name;
    explicit Course(const string& str) {
        name = str;
    }
};

struct Week {
    string name;
    explicit Week(const string& str) {
        name = str;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle(const Specialization& specInput,
                 const Course& courseInput,
                 const Week& weekInput) {
        specialization = specInput.name;
        course = courseInput.name;
        week = weekInput.name;
    }
};
