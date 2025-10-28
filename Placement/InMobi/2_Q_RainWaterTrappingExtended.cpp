/* Trapping Rainwater with Slope and Capacity
Problem Statement

You are given:

n columns with heights height[i].

A slope s applied to the ground (so effective height of column i is H[i] = height[i] + s * i).

A maximum water-holding capacity cap[i] for each column.

Goal: Determine the total amount of rainwater trapped between the columns, considering:

Water accumulates above a column only if it's lower than the surrounding walls.

The trapped water cannot exceed the column's capacity cap[i].

Approach

The problem is an extension of the classic Trapping Rain Water problem. We use a prefix-suffix scan (or two-pointer approach) with a modification for slope and capacity.

Calculate Effective Heights

H[i]=height[i]+s⋅i

Compute Maximum Heights from Left and Right

L[i]=max(H[0..i])

R[i]=max(H[i..n−1])

Calculate Trapped Water

For each column i:

water_level=min(L[i],R[i])

water_raw=water_level−H[i]

Only positive water_raw counts.

Apply the capacity constraint:

water_trapped=min(water_raw,cap[i])

Sum for All Columns

total_trapped_water=
i=0
∑
n−1
water_trapped[i]

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

long long trapRainwaterWithSlope() {
    int n;
    long long s;
    cin >> n >> s;

    vector<long long> height(n), cap(n);
    for (int i = 0; i < n; ++i) cin >> height[i];
    for (int i = 0; i < n; ++i) cin >> cap[i];

    // Step 1: Effective Heights with slope
    vector<long long> H(n);
    for (int i = 0; i < n; ++i) {
        H[i] = height[i] + s * i;
    }

    // Step 2: Left and Right maximums
    vector<long long> L(n), R(n);
    L[0] = H[0];
    for (int i = 1; i < n; ++i) {
        L[i] = max(L[i-1], H[i]);
    }

    R[n-1] = H[n-1];
    for (int i = n-2; i >= 0; --i) {
        R[i] = max(R[i+1], H[i]);
    }

    // Step 3: Calculate trapped water with capacity
    long long total_water = 0;
    for (int i = 0; i < n; ++i) {
        long long water_level = min(L[i], R[i]);
        long long water_raw = water_level - H[i];
        if (water_raw > 0) {
            total_water += min(water_raw, cap[i]);
        }
    }

    return total_water;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << trapRainwaterWithSlope() << "\n";
    return 0;
}
