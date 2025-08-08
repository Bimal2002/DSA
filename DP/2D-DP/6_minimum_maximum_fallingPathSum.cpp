#include<bits/stdc++.h>
using namespace std;
int getMaxUtils(vector<vector<int>>&matrix,int i,int j,int n,int m,vector<vector<int>>&dp){
    if(j <0 || j>= m) return -1e9;
    if(i==0) return matrix[0][j];
    if(dp[i][j]!=-1) return dp[i][j];

    int up = matrix[i][j] + getMaxUtils(matrix,i-1,j,n,m,dp);
    int leftDia = matrix[i][j] + getMaxUtils(matrix,i-1,j-1,n,m,dp);
    int rightDia = matrix[i][j] + getMaxUtils(matrix,i-1,j+1,n,m,dp);
    return dp[i][j] = max(up,max(leftDia,rightDia));

}
int getMaxPathSum(vector<vector<int>>&matrix){
     int n = matrix.size();
     int m = matrix[0].size();
     int mini = INT_MIN;
     vector<vector<int>>dp(n,vector<int>(m,-1));
     for(int j=0;j<m;j++){
        int ans = getMaxUtils(matrix,n-1,j,n,m,dp);
        mini = max(mini,ans);
     }

     return mini;

}
int main() {
    // Define the matrix as a 2D vector
    vector<vector<int>> matrix{{1, 2, 10, 4},
                                {100, 3, 2, 1},
                                {1, 1, 20, 2},
                                {1, 2, 2, 1}};
    
    // Call the getMaxPathSum function and print the result
    cout << getMaxPathSum(matrix);

    return 0;
}