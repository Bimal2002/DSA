#include<bits/stdc++.h>
using namespace std;

// Tabular approach
int solveT(int n,int m,vector<vector<int>>&maze,vector<vector<int>>&dp){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i>0 && j>0 && maze[i][j]==-1){
                dp[i][j]=0;
                continue;
            }
            if(i==0 && j==0){
               dp[i][j]=1;
               continue;
            } 
            int up=0,left =0;
            if(i>0) up =dp[i-1][j];
            if(j>0) left = dp[i][j-1];

            dp[i][j] = up+left;

        }
    }
    return dp[n-1][m-1];
}
int mazeObstaclesT(int n,int m,vector<vector<int>>& maze){
   vector<vector<int>>dp(n,vector<int>(m,-1));
   return solveT(n,m,maze,dp);
}
// Memorization
int solve(int i,int j,vector<vector<int>>&maze,vector<vector<int>>&dp){
     if(i>0 && j>0 && maze[i][j]==-1) return 0;
     if(i==0 && j==0 ) return 1;
     if(i<0 || j<0) return 0;
     if(dp[i][j]!=-1)return dp[i][j];
     int up =0, left=0;
     up = solve(i-1,j,maze,dp);
     left = solve(i,j-1,maze,dp);
     return dp[i][j] = up + left;
}
int mazeObstacles(int n,int m , vector<vector<int>>&maze){
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return solve(n-1,m-1,maze,dp);
}
int main() {
    vector<vector<int>> maze{
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}
    };

    int n = maze.size();
    int m = maze[0].size();

    cout << "Number of paths with obstacles: " << mazeObstacles(n, m, maze) << endl;
    cout<<"Res using Tabular approach: "<< mazeObstaclesT(n,m,maze);
    return 0;
}