#include<bits/stdc++.h>
using namespace std;
int n,m;
int dr[4]={-1,1,0,0},dc[4]={0,0,-1,1};
void dfs(int r,int c,vector<vector<int>>&vis,vector<string>&grid){
    vis[r][c]=1;
    for(int i=0;i<4;i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr>=0 && nr<n && nc>=0 && nc < m && !vis[nr][nc] && grid[nr][nc]=='R'){
            dfs(nr,nc,vis,grid);
        }
    }
}
int solve(vector<string>&str){
    n = str.size();
    m = str[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
    int cnt =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && str[i][j]=='R'){
               dfs(i,j,vis,str);
               cnt++;
            }
        }
    }
    return cnt;
}
int main(){
    int n;
    cin>>n;
    vector<string>str;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        str.push_back(s);
    }
    int ans = solve(str);
    cout<<ans;
}