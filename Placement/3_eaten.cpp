/*
🧬 Problem statement (formulated version)

You are given:

An array type[] of characters ('A', 'B', 'C', …) representing microorganism species.

An array size[] of integers of the same length representing their sizes.

Each organism can eat one of its immediate neighbors (left or right) if:

The neighbor is of a different type, and

The neighbor has a smaller size.

If both left and right neighbors are eligible to be eaten, the organism will prefer to eat the left neighbor.

When an organism eats another:

The eaten organism is removed.

The eater remains (its size and type stay the same).

After eating, the array shrinks, and the process continues.

The simulation continues until no more eating is possible.

You need to return the final state of the organisms — both type and size arrays.

*/


#include <bits/stdc++.h>
using namespace std;

void simulate(vector<char>& type, vector<int>& size) {
    bool changed = true;
    while (changed) {
        changed = false;
        int n = type.size();
        for (int i = 0; i < n; i++) {
            bool ate = false;

            // Check left first (preferred)
            if (i > 0 && type[i] != type[i - 1] && size[i] > size[i - 1]) {
                type.erase(type.begin() + (i - 1));
                size.erase(size.begin() + (i - 1));
                changed = true;
                ate = true;
                break; // restart simulation
            }

            // Check right
            if (i < n - 1 && type[i] != type[i + 1] && size[i] > size[i + 1]) {
                type.erase(type.begin() + (i + 1));
                size.erase(size.begin() + (i + 1));
                changed = true;
                ate = true;
                break; // restart simulation
            }
        }
    }
}

int main() {
    vector<char> type = {'A', 'B', 'C', 'A'};
    vector<int> size = {5, 3, 4, 2};

    simulate(type, size);

    cout << "Final organisms:\n";
    for (char c : type) cout << c << " ";
    cout << "\n";
    for (int s : size) cout << s << " ";
    cout << "\n";

    return 0;
}
