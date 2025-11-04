#include <bits/stdc++.h>
using namespace std;

vector<long long> special_numbers;

void precompute() {
    const int maxLen = 18;
    set<long long> st;

    for (int mask = 1; mask < (1 << 9); mask++) {
        string res = "";
        for (int d = 0; d < 9; d++) {
            if (mask & (1 << d)) {
                res += string(d + 1, '1' + d); // digit (1+d), repeated (d+1) times
            }
        }

        if (res.size() > maxLen) continue;
        sort(res.begin(), res.end());

        do {
            if (res.size() > 18) continue;
            try {
                long long val = stoll(res);
                st.insert(val);
            } catch (...) {
                continue; // skip overflowed numbers
            }
        } while (next_permutation(res.begin(), res.end()));
    }

    special_numbers.assign(st.begin(), st.end());
}

long long findSpecialNumber(long long N) {
    auto it = upper_bound(special_numbers.begin(), special_numbers.end(), N);
    if (it == special_numbers.end()) return -1; // or handle differently
    return *it;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int T;
    cin >> T;
    while (T--) {
        long long N;
        cin >> N;
        cout << findSpecialNumber(N) << "\n";
    }
}
