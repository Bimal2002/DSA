/*
🧩 Problem 1 — Minimum Cost Satisfaction (Knapsack Variant)
Problem Statement

You are given three integer arrays A, B, and C, each of length N:

A[i] → represents the satisfaction value of item i

B[i] → represents the calorie cost (or weight) of item i

C[i] → represents the monetary cost of choosing item i

You are also given two integers:

X → the minimum required total satisfaction

Y → the maximum allowed total calories

Your Task

Select a subset of items such that:

The total satisfaction (sum of chosen A[i]) is at least X

The total calories (sum of chosen B[i]) is at most Y

The total cost (sum of chosen C[i]) is minimized

If it’s not possible to satisfy these conditions, return -1.


*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, X, Y;
vector<int> A, B, C;
int dp[105][105][105]; // dp[index][satisfaction][calories]

// Recursive function
int solve(int i, int s, int c)
{
    if (c > Y)
        return INF;                // Exceeded calorie limit
    if (i == n)                    // All items processed
        return (s >= X) ? 0 : INF; // If target met, cost 0 else invalid

    int &ans = dp[i][s][c];
    if (ans != -1)
        return ans;

    // Option 1: skip
    ans = solve(i + 1, s, c);

    // Option 2: take current item
    int newS = min(X, s + A[i]); // cap at X
    int newC = c + B[i];
    if (newC <= Y)
        ans = min(ans, C[i] + solve(i + 1, newS, newC));

    return ans;
}

int main()
{
    cin >> n;
    A.resize(n);
    B.resize(n);
    C.resize(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];
    for (int i = 0; i < n; i++)
        cin >> C[i];
    cin >> X >> Y;

    memset(dp, -1, sizeof(dp));
    int result = solve(0, 0, 0);
    cout << (result >= INF ? -1 : result) << endl;
    return 0;
}
