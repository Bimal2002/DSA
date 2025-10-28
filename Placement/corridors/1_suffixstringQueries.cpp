#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int suffixQueries(const string &S, const vector<string> &queries) {
    int N = (int)S.size();
    vector<string> suffixes;
    suffixes.reserve(N);

    // Step 1: Create all suffixes
    for (int i = 0; i < N; ++i)
        suffixes.push_back(S.substr(i));

    // Step 2: Sort all suffixes lexicographically
    sort(suffixes.begin(), suffixes.end());

    long long total = 0;

    // Step 3: Process queries
    for (const string &T : queries) {
        auto it = lower_bound(suffixes.begin(), suffixes.end(), T);

        if (it != suffixes.end()) {
            string current = *it;
            if (current.find(T) == 0) {
                total = (total + current.length()) % MOD;
            }
        }
    }

    return (int)total;
}

int main() {
    string S = "azadpogtykhk";
    vector<string> queries = {"azad", "pog", "yk", "star"};

    cout << suffixQueries(S, queries) << "\n";
    return 0;
}
