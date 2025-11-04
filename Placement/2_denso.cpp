#include <bits/stdc++.h>
using namespace std;

int nonDivisibleSubset(int k, vector<int> S) {
    vector<int> freq(k, 0);
    
    // Count remainders
    for (int num : S)
        freq[num % k]++;
    
    int res = min(freq[0], 1);  // Only one number divisible by k allowed
    
    // Pair remainders (r, k-r)
    for (int r = 1; r <= k/2; r++) {
        if (r != k - r)
            res += max(freq[r], freq[k - r]);
    }
    
    // Special case: if k is even, include one from remainder k/2
    if (k % 2 == 0)
        res++;
    
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> S(n);
    for (int i = 0; i < n; i++) cin >> S[i];
    
    cout << nonDivisibleSubset(k, S) << endl;
    return 0;
}
