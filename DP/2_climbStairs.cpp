#include <bits/stdc++.h>
using namespace std;
// memorization T.C = O(n), S.C = O(n)
int fib(int n, vector<int> &dp) { // pass by reference
    if (n <= 1) return 1;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fib(n-1, dp) + fib(n-2, dp);
}

int main() {
    int n = 5;


    vector<int> dp(n+1, -1); // declare in main
    cout <<"Memorization Result: "<< fib(n, dp)<<endl; // pass it to the function
    // for tabular method T.C = O(n), S.C = O(n)
    vector<int>dp1(n+1,-1);
    dp1[0]=1,dp1[1]=1;

    for(int i=2;i<=n;i++){

        dp1[i] = dp1[i-1]+dp1[i-2];
    }
    cout<<"Tabular Result : "<<dp1[n]<<endl;


    // Space Optimization  T.C = O(n), S.C = O(1)
    int prev2=1,prev=1;
    for(int i=2;i<=n;i++){
        int curr_i = prev2+ prev;
        prev2 = prev;
        prev = curr_i;
    }

    cout<<"Result using Space Optimization : "<<prev;
}

