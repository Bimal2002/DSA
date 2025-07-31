#include<bits/stdc++.h>
using namespace std;
int shortestPath(vector<vector<int>>&grid,pair<int,int>&source,pair<int,int>&destination){
    
    if(source.first == destination.first && source.second == destination.second){
        return 0;
    }

    int n = grid.size(),m = grid[0].size();
    vector<vector<int>>dist(n,vector<int>(m,1e9));
    queue<pair<int,pair<int,int>>>q;
    q.push({0,{source.first,source.second}});
    dist[source.first][source.second]=0;
    
    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int dis = it.first;
        int r = it.second.first;
        int c = it.second.second;
        if(r== destination.first && c == destination.second) return dis;

        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >=0 && nr < n && nc>=0 && nc <m && grid[nr][nc]==1 && dis + 1 < dist[nr][nc]){
                dist[nr][nc]= 1 + dis;
                q.push({dis+1,{nr,nc}});

            }
        }

    }
  return -1;

}
int main()
{
    // Driver Code.

    pair<int, int> source, destination;
    source.first = 0;
    source.second = 1;
    destination.first = 2;
    destination.second = 2;

    vector<vector<int>> grid = {{1, 1, 1, 1},
                                {1, 1, 0, 1},
                                {1, 1, 1, 1},
                                {1, 1, 0, 0},
                                {1, 0, 0, 1}};

   

    int res = shortestPath(grid, source, destination);

    cout << res;
    cout << endl;

    return 0;
}
 