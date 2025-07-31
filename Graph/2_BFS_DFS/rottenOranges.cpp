#include <bits/stdc++.h>
using namespace std;
int rottenOranges(vector<vector<int>> &grid){
    int n = grid.size(),m = grid[0].size();
    int cnt = 0, tot=0,days=0;
    queue<pair<int,int>>q; // to store the co-ordinates(x,y)
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]!=0) tot ++;
            if(grid[i][j]==2) q.push({i,j});
        }
    }
    // cout<<"Total"<<tot;
    int dr[]={-1,1,0,0},dc[]={0,0,-1,1};

    while (!q.empty())
    {
       int k = q.size();
       cnt +=k;
       while(k--){
          int r = q.front().first;
          int c = q.front().second;
          q.pop();
          for(int i=0;i<4;i++){
            int nr = r + dr[i],nc = c + dc[i];
            if(nr>=0 && nr <n && nc>=0 && nc <m && grid[nr][nc] ==1){
                grid[nr][nc] =2;
                q.push({nr,nc});
            }
            
          }
       }
       if(!q.empty()) days++;
    }
    return tot == cnt ? days :-1;
    
}
int main()
{
    vector<vector<int>> grid = { 
        {2,1,1},
        {0,1,1},
        {1,1,1}
     };
     int ans = rottenOranges(grid);
     cout<<ans;
}