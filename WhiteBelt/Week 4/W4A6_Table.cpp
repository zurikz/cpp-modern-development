#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    ifstream input("input.txt");

    int rows, columns;
    input >> rows >> columns;

    if (input) {
        for (int r = 1; r <= rows; ++r) {
            for (int col = 1; col <= columns; ++col) {
                int cell;
                input >> cell;

                input.ignore(1);

                cout << setw(10) << cell;

                if (col < columns) {
                    cout << ' ';
                }
            }

            if (r < rows) {
                cout << endl;
            }
        }
    } else {
        cout << "Error!";
    }
    return 0;
}
