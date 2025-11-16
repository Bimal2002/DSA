/*
🏞️ 1) Max Profit with Directed Canals (Graph + DP)
🧩 Problem restatement

You have:

N villages (nodes)

M directed canals (edges)

Each village i has a value a[i]` (like price of a commodity).

You can:

Choose one “buy” village and one later “sell” village reachable via canals.

You can skip trading (profit = 0).

You cannot travel back (no reverse traversal).

Goal → find maximum profit = a[sell] - a[buy],
such that there exists a path buy → sell.

*/

#include<bits/stdc++.h>
using namespace std;
int main(){
      int n,m;
      cin>>n>>m;
      vector<int>a(n+1);
      for(int i=0;i<=n;i++) cin>>a[i];

      vector<vector<int>>adj(n+1);
      vector<int>indeg(n+1,0);
      for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indeg[v]++;
      }
      // toposort
      queue<int>q;
      for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
      }

      vector<int>topo;
      while (!q.empty())
      {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for(int v : adj[u]){
            indeg[v]--;
            if(indeg[v]==0){
                q.push(v);
            }
        }
      }

      const int INF = 1e9;
      vector<int>dp(n+1,INF);
      for(int i=1;i<=n;i++){
        dp[i]= a[i];
      }
      int ans = INF;
      for(int u : topo){
        for(int  v : adj[u]){
            ans = max(ans, a[v]-dp[u]);
            dp[v]= min(dp[v],dp[u]);
        }
      }
      
      
}