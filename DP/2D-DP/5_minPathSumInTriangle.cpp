#include<bits/stdc++.h>
using namespace std;
int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>&dp,int n){
    if(dp[i][j]!=-1) return dp[i][j];

    if(i==n-1) return triangle[i][j];
    int down = triangle[i][j] + solve(i+1,j,triangle,dp,n);
    int diagonal =triangle[i][j] + solve(i+1,j+1,triangle,dp,n);
    return dp[i][j] = min(down,diagonal);

}
int minimumPathSum(vector<vector<int>>&triangle,int n){
      vector<vector<int>>dp(n,vector<int>(n,-1));
      return solve(0,0,triangle,dp,n);
}
int main() {
    // Define the triangle as a 2D vector
    vector<vector<int> > triangle{{1},
                                   {2, 3},
                                   {3, 6, 7},
                                   {8, 9, 6, 10}};

    // Get the number of rows in the triangle
    int n = triangle.size();

    // Call the minimumPathSum function and print the result
    cout << minimumPathSum(triangle, n);

    return 0;
}
