#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int numOfOperations;
    cin >> numOfOperations;

    vector<int> queue;
    vector<int> worryCount;

    string operation;
    int operationArg;

    for (int i = 0; i < numOfOperations; ++i) {

        cin >> operation;

        if (operation == "WORRY_COUNT") {
            int sum = 0;
            for (auto& x : queue)
                sum += x;
            worryCount.push_back(sum);
            continue;
        }

        cin >> operationArg;

        if (operation == "COME") {
            queue.resize(queue.size() + operationArg);
        }

        if (operation == "WORRY") {
            ++queue[operationArg];
        }

        if (operation == "QUIET") {
            --queue[operationArg];
        }
    }

    for (auto& count : worryCount) {
        cout << count << endl;
    }
    return(0);
}
