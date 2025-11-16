
/*
Problem: Beautiful Strings
Definition

A string is called beautiful if:

Each character of the string is one of the first K lowercase English letters ('a' to 'a' + K - 1).

The string does not contain any palindrome substring of length ≥ 2.

So:

No two consecutive characters are the same.

No three consecutive characters can form a palindrome like aba.

Input

Two integers: N, K

A string S (of length N), which is already beautiful.

Task

Find the lexicographically smallest string T of length N such that:

T is beautiful.

T is lexicographically larger than S.

If no such string exists, return -1.

Notes

Lexicographic order = dictionary order.
Examples:

"abc" < "abd"

"abd" < "abe"

"ab" < "aba"

🧠 Intuition

We need the next lexicographically greater “beautiful” string.

Think of it like generating the next permutation but with special beauty constraints.

✅ Constraints for "Beautiful":

For every index i:

S[i] != S[i-1] (avoid 2-length palindrome)

S[i] != S[i-2] (avoid 3-length palindrome)

So when we build or modify the string, we must check only the last two characters.

🔍 Approach (Greedy + Backtracking)

Start from rightmost position i = N-1.

Try to increment S[i] to the next allowed character (within 'a' + K - 1).

Check if it keeps the string beautiful:

S[i] != S[i-1] and S[i] != S[i-2]

If valid:

Fix S[i], and for all j > i, fill with the smallest possible valid characters from 'a' upwards that maintain beauty.

That gives the smallest lexicographically valid string > S.

If not possible, move left (i--).

If no such position exists → return -1.



*/




#include <bits/stdc++.h>
using namespace std;

bool isValid(string &s, int i, char c) {
    if (i >= 1 && s[i-1] == c) return false; // avoid "aa"
    if (i >= 2 && s[i-2] == c) return false; // avoid "aba"
    return true;
}

string nextBeautiful(int N, int K, string S) {
    for (int i = N - 1; i >= 0; i--) {
        for (char c = S[i] + 1; c < 'a' + K; c++) {
            if (isValid(S, i, c)) {
                S[i] = c;
                // fill remaining with smallest valid chars
                for (int j = i + 1; j < N; j++) {
                    for (char x = 'a'; x < 'a' + K; x++) {
                        if (isValid(S, j, x)) {
                            S[j] = x;
                            break;
                        }
                    }
                }
                return S;
            }
        }
    }
    return "-1";
}

int main() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    cout << nextBeautiful(N, K, S);
}
