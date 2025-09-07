#include<bits/stdc++.h>
using namespace std;
void dfs(int V,vector<vector<int>>&adj,int src,int dest,vector<vector<int>>&allPaths,vector<int>&paths){
    paths.push_back(src);
    if(src== dest){
        allPaths.push_back(paths);
    }else{
        for(auto adjN : adj[src]){
            dfs(V,adj,adjN,dest,allPaths,paths);
        }
    }
    paths.pop_back();
}
vector<vector<int>>findPaths(int V, vector<vector<int>>edges,int src,int dest){
         vector<vector<int>>adj(V);
         for(auto it : edges){
            adj[it[0]].push_back(it[1]);
         }
         vector<vector<int>>allPaths;
         vector<int>paths;
         dfs(V,adj,src,dest,allPaths,paths);
         return allPaths;
}
int main() {
    vector<vector<int>> edges = {{0, 3}, {0, 1}, {1, 3}, {2, 0}, {2, 1}};
    int src = 2, dest = 3;
    int v = 4;

    // Find all paths from source to destination
    vector<vector<int>> paths = findPaths(v, edges, src, dest);

    // Print all the paths
    for (const auto &path : paths) {
        for (int vtx : path) {
            cout << vtx << " ";
        }
        cout << endl;
    }

    return 0;
}