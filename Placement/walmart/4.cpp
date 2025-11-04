#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int S0;
    cin >> S0;

    unordered_map<string, int> value;    // relation → checkpoint value
    unordered_map<string, int> children; // relation → child count

    value[""] = S0; // root (starting checkpoint)

    for (int i = 0; i < N - 1; i++) {
        string relation;
        int X;
        cin >> relation >> X;

        value[relation] = X;

        // Determine parent (relation without last character)
        string parent = relation.substr(0, relation.size() - 1);
        children[parent]++;
    }

    int sum = 0;

    // Check for nodes with multiple downstream connections
    for (auto &it : children) {
        if (it.second > 1) {
            string relation = it.first;
            sum += value[relation]; // add the checkpoint value
        }
    }

    cout << sum << endl;
    return 0;
}
