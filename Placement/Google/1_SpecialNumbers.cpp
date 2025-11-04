// # **Problem: Smallest Special Number**

// ## **Problem Statement**

// A number `X` is said to be **special** if it satisfies the following condition:

// * Every digit `d` present in `X` occurs exactly `d` number of times in `X`.

// **Task:**

// Given an integer `N`, find the **smallest special number strictly greater than `N`**.

// ---

// ### **Input Format**

// * The first line contains an integer `T` — the number of test cases.
// * Each of the next `T` lines contains a single integer `N`.

// ---

// ### **Output Format**

// * For each test case, print the smallest special number strictly greater than `N`.

// ---

// ### **Constraints**

// * (1 \le T \le 10^5)
// * (1 \le N \le 10^{18})

// ---

// ### **Examples**

// **Input**

// ```
// 2
// 2
// 23
// ```

// **Output**

// ```
// 22
// 122
// ```

// **Explanation**

// 1. For `N = 2`, the smallest special number greater than 2 is `22` (digit 2 appears 2 times).
// 2. For `N = 23`, the smallest special number greater than 23 is `122` (digit 1 appears 1 time, digit 2 appears 2 times).

// ---

// # **Solution Approach**

// 1. **Precompute all special numbers** using **bitmasking**:

//    * Each subset of digits 1–9 is represented by a bitmask.
//    * For each digit `d` in the subset, repeat `d` exactly `d` times.
//    * Generate all **permutations** of the string.
//    * Store results in a **set** to avoid duplicates.
// 2. Convert the set to a **sorted vector**.
// 3. For each query `N`, use `upper_bound` to find the **smallest special number greater than N**.



#include <bits/stdc++.h>
using namespace std;

vector<long long> special_numbers;

// Precompute all special numbers
void precompute() {
    set<long long> sset;  // use set to avoid duplicates
    const int MAX_LEN = 18;

    for (int mask = 1; mask < (1 << 9); mask++) { // all subsets of digits 1..9
        string s = "";
        for (int d = 0; d < 9; d++) {
            if (mask & (1 << d)) {
                s += string(d + 1, '1' + d); // repeat digit (d+1) exactly (d+1) times
            }
        }

        if ((int)s.size() > MAX_LEN) continue; // skip too long strings

        sort(s.begin(), s.end());
        do {
            sset.insert(stoll(s)); // convert string to number
        } while (next_permutation(s.begin(), s.end()));
    }

    special_numbers.assign(sset.begin(), sset.end()); // sorted vector
}

// Find smallest special number > N
long long next_special_number(long long N) {
    auto it = upper_bound(special_numbers.begin(), special_numbers.end(), N);
    return *it;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute(); // precompute all special numbers

    int T;
    cin >> T;
    while (T--) {
        long long N;
        cin >> N;
        cout << next_special_number(N) << "\n";
    }
    return 0;
}
// ```

// ---

// ### **How It Works**

// 1. **Bitmasking**: represents subsets of digits 1–9.
// 2. **Digit repetition**: each digit `d` appears exactly `d` times.
// 3. **Permutations**: generate all unique numbers from that string.
// 4. **Set → Vector**: ensures uniqueness and allows **binary search**.
// 5. **Query**: `upper_bound` efficiently finds the smallest special number > `N`.

// ---

// ### **Dry Run Example**

// * Input `N = 23`
// * Precomputed special numbers: `[1, 22, 122, 1333, 3133, 3313, 3331, ...]`
// * `upper_bound(23)` → `122` → output

// ---

// This solution is **fast enough** even for large `T` and `N` because all expensive work is done **once in precomputation**.

// ---

// If you want, I can also make an **optimized version** that avoids generating all permutations, which makes it much **faster and smaller in memory**.

// Do you want me to show that optimization?
