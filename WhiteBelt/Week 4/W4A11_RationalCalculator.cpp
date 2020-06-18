#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int num, int denom) {
        if (denom == 0) {
            throw invalid_argument("Invalid argument");
        }

        const int GCD = gcd(num, denom);
        numerator = num / GCD;
        denominator = denom / GCD;

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

private:
    int numerator;
    int denominator;
};

bool operator==(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() &&
           lhs.Denominator() == rhs.Denominator();
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    return {
            lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
            lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    return {
            lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
            lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    return {lhs.Numerator() * rhs.Numerator(),
            lhs.Denominator() * rhs.Denominator()};
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) {
        throw domain_error("Division by zero");
    }
    return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

bool operator<(const Rational& lhs, const Rational& rhs) {
    return (lhs - rhs).Numerator() < 0;
}

istream& operator>>(istream& stream, Rational& number) {
    int numerator, denominator;
    if (stream >> numerator) {
        stream.ignore();
        if (stream >> denominator) {
            number = Rational(numerator, denominator);
        } else {
            throw invalid_argument("Invalid argument");
        }
    } else {
        throw invalid_argument("Invalid argument");
    }
    return stream;
}

ostream& operator<<(ostream& stream, const Rational& number) {
    return stream << number.Numerator() << '/'
                  << number.Denominator();
}

int main() {
    try {
        Rational lhs;
        cin >> lhs;

        cin.ignore(1);
        char operation;
        cin >> operation;
        cin.ignore(1);

        Rational rhs;
        cin >> rhs;

        if (operation == '+') {
            cout << lhs + rhs;
        } else if (operation == '-') {
            cout << lhs - rhs;
        } else if (operation == '*') {
            cout << lhs * rhs;
        } else if (operation == '/') {
            cout << lhs / rhs;
        }
    } catch (invalid_argument& error) {
        cout << error.what();
    } catch (domain_error& error) {
        cout << error.what();
    }

    return 0;
}
