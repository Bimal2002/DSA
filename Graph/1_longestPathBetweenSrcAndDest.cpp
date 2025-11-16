#include<bits/stdc++.h>
using namespace std;
int longestPath(vector<vector<int>>&adj,int src,int dest,vector<bool>&vis){
    if(src == dest) return 0;
    int maxLen = -1;
    vis[src]= true;
    for(int v = 0;v<adj.size();v++){
        if(adj[src][v] && !vis[v]){
            int path = longestPath(adj,v,dest,vis);
            if(path !=-1){
                maxLen = max(maxLen,1+path);
            }
        }
    }
    vis[src]=false; // backtrack
    return maxLen;
}
int main(){
    vector<vector<int>> adj = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 1},
        {0, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 1, 0}
    };

    int n = adj.size();
    int src = 0;
    int dest = 5;

    vector<bool> visited(n, false);

    int result = longestPath(adj, src, dest, visited);
    cout<<result;
}