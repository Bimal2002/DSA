#include <bits/stdc++.h>
using namespace std;

long long solve(string S) {
    vector<int> last(256, -1);
    int n = S.size();

    // Step 1: record last index of each char
    for (int i = 0; i < n; i++)
        last[S[i]] = i;

    long long totalScore = 0;
    int start = 0, end = 0;

    // Step 2: partition
    for (int i = 0; i < n; i++) {
        end = max(end, last[S[i]]);
        if (i == end) {
            int len = end - start + 1;
            totalScore += 1LL * len * len;
            start = i + 1;
        }
    }

    return totalScore;
}

int main() {
    string S;
    cin >> S;
    cout << solve(S) << endl;
    return 0;
}
