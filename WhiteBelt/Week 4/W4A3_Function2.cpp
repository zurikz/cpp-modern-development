#include <algorithm>
#include <vector>
using namespace std;

class FunctionPart {
public:
    FunctionPart(const char& newOperation, const double& newValue) {
        operation = newOperation;
        value = newValue;
    }
    double Apply(double& sourceValue) const {
        if (operation == '+') {
            return sourceValue + value;
        } else if (operation == '-') {
            return sourceValue - value;
        } else if (operation == '*') {
            return sourceValue * value;
        } else {
            return sourceValue / value;
        }
    }
    void Invert() {
        if (operation == '+') {
            operation = '-';
        } else if (operation == '-') {
            operation = '+';
        } else if (operation == '*') {
            operation = '/';
        } else {
            operation = '*';
        }
    }
private:
    char operation;
    double value;
};

class Function {
public:
    void AddPart(const char& operation, const double& value) {
        parts.push_back(FunctionPart(operation, value));
    }
    double Apply(double value) const {
        for (const FunctionPart& part : parts) {
            value = part.Apply(value);
        }
        return value;
    }
    void Invert() {
        for (FunctionPart& part : parts) {
            part.Invert();
        }
        reverse(begin(parts), end(parts));
    }
private:
    vector<FunctionPart> parts;
};
