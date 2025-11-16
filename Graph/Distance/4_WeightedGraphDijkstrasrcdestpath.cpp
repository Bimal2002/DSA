#include<bits/stdc++.h>
using namespace std;
vector<int>dijkstraPath(int n,vector<vector<pair<int,int>>>&adj,int src,int dest){
    vector<int>dist(n,INT_MAX),parent(n,-1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int d = it.first;
        int u = it.second;
        if(u == dest) break;
        for(auto ed : adj[u]){
            int v = ed.first;
            int wt = ed.second;

            if(dist[u] + wt < dist[v]){
                dist[v] = dist[u]+wt;
                parent[v]=u;
                pq.push({dist[v],v});
            }
        }
    }

    if(dist[dest]==INT_MAX) return {};
    vector<int>path;
    for(int v = dest;v!=-1;v= parent[v]){
        path.push_back(v);
    }
    reverse(path.begin(),path.end());
    return path;
}

int main() {
    int n = 5;
    vector<vector<pair<int,int>>> adj(n);

    vector<tuple<int,int,int>> edges = {
        {0,1,2}, {0,2,4},
        {1,2,1}, {1,3,7},
        {2,4,3}, {3,4,1}
    };

    for (auto &[u,v,w] : edges) {
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});   // undirected
    }

    int src = 0, dest = 4;

    vector<int> path = dijkstraPath(n, adj, src, dest);



}