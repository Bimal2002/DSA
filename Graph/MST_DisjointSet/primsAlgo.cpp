#include <bits/stdc++.h>
using namespace std;

pair<int, vector<pair<int, int>>> MST(int V, vector<vector<int>> adj[])
{
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, 0, -1}); // {wt,node,parent}
    vector<int> vis(V, 0);
    vector<pair<int, int>> mst_edges;
    int sum = 0;
    while (!pq.empty())
    {
        // auto [wt, node, parent] = pq.top();
        int wt, node, parent;
        std::tie(wt, node, parent) = pq.top();

        pq.pop();
        if (vis[node])
            continue;

        if (parent != -1)
        {
            mst_edges.push_back({parent, node});
        }
        sum += wt;
        vis[node] = 1;
        for (auto it : adj[node])
        {
            int wt = it[1];
            int adjNode = it[0];
            if (!vis[adjNode])
            {
                pq.push({wt, adjNode, node});
            }
        }
    }
    return {sum, mst_edges};
}
typedef pair<int,pair<int,int>>P;
pair<int,vector<int>>MST_withEdges(int V,vector<vector<int>>adj[]){
   priority_queue<P,vector<P>,greater<P>>pq;
   pq.push({0,{0,-1}});
   vector<bool>vis(V,false);
   vector<pair<int,int>>mst_edges;
   int sum =0;
   while(!pq.empty()){
      auto it = pq.top();
      pq.pop();
      int w = it.first;
      int node = it.second.first;
      int parent = it.second.second;
      if(vis[node]) continue;
      if(parent !=-1){
        mst_edges.push_back({parent,node});
      }
      sum += w;
      for(auto it : adj[node]){
        int wt = it[1];
        int adjN = it[0];
        if(!vis[adjN]){
            pq.push({wt,{adjN,node}});
        }
      }
   }
   return {sum,mst_edges};
}
int spanningTree(int V, vector<vector<int>> adj[])
{
    // {wt,node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(V, 0);
    pq.push({0, 0});
    int sum = 0;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;
        if (vis[node] == 1)
            continue;

        vis[node] = 1;
        sum += wt;
        for (auto it : adj[node])
        {
            int adjNode = it[0], edw = it[1];
            if (!vis[adjNode])
            {
                pq.push({edw, adjNode});
            }
        }
    }
    return sum;
}
int main()
{

    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<int>> adj[V];
    for (auto it : edges)
    {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }

    int sum = spanningTree(V, adj);
    cout << "The sum of all the edge weights: " << sum << endl;

    auto result = MST(V, adj);
    int mst_sum = result.first;
    auto &mst_edges = result.second;

    cout << "MST total weight: " << sum << endl;
    for (auto &p : mst_edges)
    {
        cout << p.first << " - " << p.second << endl;
    }
    return 0;
}