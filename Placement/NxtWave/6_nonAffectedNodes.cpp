#include<bits/stdc++.h>
using namespace std;
int N;
int X;
bool canReach(int u,vector<int>&affectedNodes,vector<vector<int>>&adj){
    queue<int>q;
    q.push(u);
    vector<int>vis(N,false);
    vis[u]=true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        if(affectedNodes[node]) return true;
        for(auto it : adj[node]){
            if(!vis[it]){
                q.push(it);
                vis[it]= true;
            }
        }
    }
    return false;
    
}
vector<int>solve(vector<vector<int>>&edges){
    vector<vector<int>>adj(N);
    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
    }

    vector<int>affectNodes(N,0);
    queue<int>q;
    q.push(X);
    affectNodes[X]=1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it : adj[node]){
            q.push(it);
            affectNodes[it]=1;
        }
    }

    vector<int>unAffected;
    for(int i=0;i<N;i++){
        if(!affectNodes[i]){
            unAffected.push_back(i);
        }
    }
    for(int u : unAffected){
        if(canReach(u,affectNodes,adj)){
             vector<int>arr(N);
             iota(arr.begin(),arr.end(),0);
             return arr;
        }
    }

    return unAffected;
    
    
}
int main(){
    int n,x;
    // n = 6
    // edges = [(0,1),(1,2),(2,3),(4,2),(5,4)]
    // x = 1
    cin>>n>>x;
    N = n;
    X= x;

    vector<vector<int>>edges = {{0,1},{1,2},{2,3},{4,2},{5,4}};
    vector<int>ans = solve(edges);
    for(int num: ans){
        cout<<num<<" ";
    }

}