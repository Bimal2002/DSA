#include<bits/stdc++.h>
using namespace std;
// Tabular
int solveT(int m,int n,vector<vector<int>>&dp){
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0 ){
                dp[i][j]=1;
                continue;
            }

            int up = 0, left =0;
            if(i>0) up = dp[i-1][j];
            
            if(j>0) left = dp[i][j-1];

            dp[i][j] = up + left;
        }
     }
     return dp[m-1][n-1];
}
int countWaysT(int m,int n){
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return solveT(m,n,dp);
}
// Memo
int solve(int i,int j ,vector<vector<int>>&dp){
    if(i==0 && j== 0) return 1;
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int up = solve(i-1,j,dp),left =solve(i,j-1,dp);
    return dp[i][j]=up+left;

}
int countWays(int m,int n){
      vector<vector<int>>dp(m,vector<int>(m,-1));
      return solve(m-1,n-1,dp);
}
int main() {
    int m = 3;
    int n = 2;

    // Call the countWays function and print the result.
    cout << "Number of ways to reach (" << m - 1 << ", " << n - 1 << "): " << countWays(m, n) << endl;
    cout<<"Tabular Solution : "<< countWaysT(m,n);
    return 0;
}