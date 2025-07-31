#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>nearest(vector<vector<int>> grid){
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<vector<int>>dist(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>>q; // {co-ordinates,steps}
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                q.push({{i,j},0});
                vis[i][j]=1;
            }else{
                vis[i][j]=0;
            }
        }
    }
    int delRow[]={-1,0,1,0},delCol[]={0,-1,0,1};
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        dist[r][c]=steps;
        for(int i=0;i<4;i++){
            int nr = r + delRow[i];
            int nc = c + delCol[i];
            if(nr >=0 && nr <n && nc >=0 && nc <m && vis[nr][nc]==0){
                vis[nr][nc]=1;
                q.push({{nr,nc},steps+1});
            }
        }
    }
    return dist;

}
int main(){
    vector<vector<int>>grid = {
        {0,0,0},
        {0,1,0},
        {1,0,1}
    };
    vector<vector<int>>ans = nearest(grid);
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}