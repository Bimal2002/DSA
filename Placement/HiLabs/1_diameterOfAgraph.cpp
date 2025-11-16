/*
Problem Summary (as per your description)

You’re given a weighted graph (maybe undirected).
You need to:

Find the two nodes that are farthest apart — i.e. the pair (u, v) such that the shortest path distance between u and v is maximum among all pairs.

Then return the minimum cost (distance) of that farthest pair — basically the diameter of the graph.

So:

Answer = maximum shortest path distance between any two nodes

Graph edges (u, v, w):
1 —2— 2
2 —3— 3
3 —4— 4
Shortest paths:

dist(1,2)=2

dist(1,3)=5

dist(1,4)=9

dist(2,3)=3

dist(2,4)=7

dist(3,4)=4

👉 Farthest pair = (1,4), distance = 9
✅ Output: 9

Approach 1 — Using Dijkstra (for weighted graph)

Pick any node (say 1).

Run Dijkstra → find farthest node A from it.

Run Dijkstra again from A → find farthest node B.

The distance dist(A, B) = graph diameter (minimum cost between farthest pair).

💡 Works because of the “double sweep” method — same logic used for tree diameter but works in general graphs too (if all edges have non-negative weights).


*/
#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>>adj[100005]; //{node,weight}
vector<long long>dijstra(int n,int src){
     const long long INF = 1e18;
     vector<long long>dist(n+1,INF);
     priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>pq;
     pq.push({0,src});

     while (!pq.empty())
     {
        auto it = pq.top();
        int d = it.first;
        int u = it.second;
        pq.pop();
        if(d!=dist[u]) continue;
        for(auto it : adj[u]){
            int v = it.first;
            int w =it.second;
            if(dist[v] > d +w){
               dist[v] = d+w;
               pq.push({dist[v],v});
            }
        }
     }
     return dist;
     
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    // step 1 : run Dijkstra from node 1 (or any)
    auto dist1= dijstra(n,1);
    int A = max_element(dist1.begin()+1,dist1.end())- dist1.begin();

    // step 2
    auto dist2 = dijstra(n,A);
    long long diameter = *max_element(dist2.begin()+1,dist2.end());
    cout<<diameter<<endl;

}


