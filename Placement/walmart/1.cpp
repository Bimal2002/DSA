#include <bits/stdc++.h>
using namespace std;

// Function to generate all primes <= N using Sieve of Eratosthenes
vector<int> generatePrimes(int N) {
    vector<bool> isPrime(N + 1, true);
    vector<int> primes;

    if (N < 2) return primes; // no primes less than 2

    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i)
                isPrime[j] = false;
        }
    }

    for (int i = 2; i <= N; i++)
        if (isPrime[i]) primes.push_back(i);

    return primes;
}

int main() {
    int N, P;
    cin >> N >> P;

    vector<int> primes = generatePrimes(N);

    int sum = 0;
    for (int i = 0; i < (int)primes.size(); i++) {
        sum += primes[i];
        if (sum > P) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl; // if sum never exceeds P
    return 0;
}
