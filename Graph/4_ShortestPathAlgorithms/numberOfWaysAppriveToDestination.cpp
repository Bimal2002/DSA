#include<bits/stdc++.h>
using namespace std;

int countPaths(int n,vector<vector<int>>&edges){
        vector<pair<int,int>>adj[n];
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int>dist(n,INT_MAX),ways(n,0);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; // {dist,nodes}
        pq.push({0,0});
        dist[0]=0,ways[0]=1;
        int mod = 1e9+7;

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it  : adj[node]){
                int edw = it.second;
                int adjacentNode = it.first;

                if(dis+edw < dist[adjacentNode]){
                    dist[adjacentNode] = dis+ edw;
                    pq.push({dis+edw , adjacentNode});
                    ways[adjacentNode] = ways[node];
                }else if(dis+ edw == dist[adjacentNode]){
                    ways[adjacentNode] = (ways[adjacentNode]+ways[node])%mod;
                }
            }
        }
     return ways[n-1]% mod;
}

int countways(vector<vector<int>>&edges,int n){
     vector<pair<int,int>>adj[n];
     for(auto it : edges){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
     }
     vector<int>ways(n,0),dist(n,INT_MAX);
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
     dist[0]=0,ways[0]=1;
     int mod = 1e9+7;
     pq.push({0,0});
     int dr[]={-1,0,1,0},dc[]={0,1,0,-1};
     while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node]){
            int adjN = it.first,adjW = it.second;
            if(dis + adjW < dist[adjN]){
                dist[adjN]= dis+adjW;
                pq.push({adjN,adjW+adjN});
                ways[adjN] =ways[node];
            }
            else if( dis + adjW == dist[adjN]){
                ways[adjW] = (ways[node] + ways[adjN])%mod;
            }
        }
     }
     return ways[n-1]% mod;

}
int main()
{
    int n = 7;

    vector<vector<int>> edges = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, 
    {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};


    int ans = countPaths(n, edges);

    cout << ans;
    cout << endl;

    return 0;
}