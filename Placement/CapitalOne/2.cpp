#include <bits/stdc++.h>
using namespace std;

int reduceArray(vector<int>& numbers) {
    int total = 0;
    int n = numbers.size();

    while (true) {
        // Step 1: find first non-zero element
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (numbers[i] > 0) {
                idx = i;
                break;
            }
        }

        // All zero -> stop
        if (idx == -1) break;

        int x = numbers[idx];
        total += x;

        // Step 2: subtract x from all >= x starting from idx
        for (int j = idx; j < n; j++) {
            if (numbers[j] >= x)
                numbers[j] -= x;
            else
                break;
        }
    }

    return total;
}

int main() {
    vector<int> numbers1 = {3, 1, 3, 2, 2};
    cout << reduceArray(numbers1) << endl; // Output: 7

    vector<int> numbers2 = {0, 4, 4, 2};
    cout << reduceArray(numbers2) << endl; // Output: 6

    return 0;
}
