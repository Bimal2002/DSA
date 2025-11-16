/*

🧩 Problem Summary

We have an array segments (or coins) where:

1 → segment contains a coin (+1 point)

0 → segment has no coin (−1 point)

Player 1 always starts and can play the first k segments.
Then Player 2 plays the remaining n−k segments.

We must find the minimum k such that
Player1Score > Player2Score.

*/



#include <bits/stdc++.h>
using namespace std;

int playSegments(vector<int> coins) {
    int n = coins.size();
    vector<int> score(n);
    
    // Convert coins into +1 (for coin) and -1 (for no coin)
    for (int i = 0; i < n; i++) {
        score[i] = (coins[i] == 1) ? 1 : -1;
    }
    
    vector<int> prefix(n + 1, 0);  // prefix[i] = sum of first i segments
    vector<int> suffix(n + 1, 0);  // suffix[i] = sum from i to end
    
    // Calculate prefix sum
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + score[i];
    }
    
    // Calculate suffix sum
    for (int i = n - 1; i >= 0; i--) {
        suffix[i] = suffix[i + 1] + score[i];
    }
    
    // Find smallest k where prefix[k] > suffix[k]
    for (int k = 0; k <= n; k++) {
        if (prefix[k] > suffix[k]) {
            return k;  // minimum segments Player1 should play
        }
    }
    
    return n;  // in worst case, must play all
}

int main() {
    vector<int> segments = {1, 1, 0, 1};
    cout << playSegments(segments) << endl;  // Output: 2
    return 0;
}

