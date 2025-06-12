// Rat in a Maze

// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and the rat cannot move to it while value 1 at a cell in the matrix represents that rat can travel through it.

// Note: In a path, no cell can be visited more than one time.


#include<bits/stdc++.h>
using namespace std;
void solve(int i,int j,vector<vector<int>>&maze,int n,string path,vector<vector<int>>&visited,vector<string>&ans){
    if(i<0 || j<0 || i>=n || j>=n || maze[i][j]==0 || visited[i][j]==1){
        return;
    }
    if(i==n-1 && j==n-1){
        ans.push_back(path);
        return;
    }
    visited[i][j]=1;
    solve(i+1,j,maze,n,path+'D',visited,ans);
    solve(i-1,j,maze,n,path+'U',visited,ans);
    solve(i,j+1,maze,n,path+'R',visited,ans);
    solve(i,j-1,maze,n,path+'L',visited,ans);
    visited[i][j]=0;

}
vector<string>findPath(vector<vector<int>>&maze,int n){
    vector<string>ans;
    if(maze[0][0]==0 || maze[n-1][n-1]==0){
        return {};
    }
    vector<vector<int>>visited(n,vector<int>(n,0));
    solve(0,0,maze,n,"",visited,ans);

    sort(ans.begin(),ans.end());
    return ans;
}
int main(){
    int n = 4;
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<string>result = findPath(maze,n);
    for(auto it:result){
        cout<<it<<endl;
    }

    
}