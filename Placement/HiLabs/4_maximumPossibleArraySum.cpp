/*
You are given three arrays:

A of size N

B of size M

K of size N

You must modify each element of A according to this rule:

For each index i (1 ≤ i ≤ N):

You can choose an index j such that:

max(1,i−K[i])≤j≤min(M,i+K[i])

Replace A[i] with A[i] * B[j].

🎯 Objective

After you modify all elements of A,
find the maximum possible sum of the modified array A.

*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<long long> A(N), B(M), K(N);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;
    for (auto &x : K) cin >> x;

    long long result = 0;

    for (int i = 0; i < N; i++) {
        int L = max(0, i - (int)K[i]);
        int R = min(M - 1, i + (int)K[i]);

        long long best;
        if (A[i] >= 0)
            best = *max_element(B.begin() + L, B.begin() + R + 1);
        else
            best = *min_element(B.begin() + L, B.begin() + R + 1);

        result += A[i] * best;
    }

    cout << result << endl;
    return 0;
}
