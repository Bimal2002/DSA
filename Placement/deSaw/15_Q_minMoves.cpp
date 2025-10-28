#include <iostream>
#include <vector>
using namespace std;

int getMinimumMoves(vector<int>& tasks) {
    int n = tasks.size();
    int moves = 0;

    for (int i = 1; i < n; i++) {
        if (tasks[i] > tasks[i - 1]) {
            moves += tasks[i] - tasks[i - 1]; // move tasks[i]-tasks[i-1] tasks to left
            tasks[i] = tasks[i - 1];          // adjust current group
        }
    }

    return moves;
}

int main() {
    vector<int> tasks = {3, 4, 3, 3, 5, 1};

    int moves = getMinimumMoves(tasks);

    cout << "Minimum moves required: " << moves << endl;
    cout << "Final tasks array: ";
    for (int t : tasks) {
        cout << t << " ";
    }
    cout << endl;

    return 0;
}
