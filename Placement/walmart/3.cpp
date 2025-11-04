#include <bits/stdc++.h>
using namespace std;

// Function to calculate sum of digits
int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int P, R, X;
    cin >> P >> R >> X;

    int N = -1, M = -1;

    // Find smallest N
    for (int i = P; i <= R; i++) {
        if (digitSum(i) == X) {
            N = i;
            break;
        }
    }

    // Find largest M
    for (int i = R; i >= P; i--) {
        if (digitSum(i) == X) {
            M = i;
            break;
        }
    }

    cout << N << endl;
    cout << M << endl;

    return 0;
}
