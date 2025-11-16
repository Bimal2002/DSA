#include<bits/stdc++.h>
using namespace std;
int timer = 1;
void dfs(int node,int parent,vector<int>&vis,vector<vector<int>>&adj,vector<int>&tin,vector<int>&low,vector<vector<int>>&bridges){
    vis[node]=1;
    tin[node] = low[node] = timer++;
    for(auto it: adj[node]){
        if(it== parent) continue;
        if(!vis[it]){
            // explore dfs
            dfs(it,node,vis,adj,tin,low,bridges);
            low[node] = min(low[node],low[it]);

            if(low[it] > tin[node]){
                 bridges.push_back({it,node});
            }

        }else{
            low[node] = min(low[node],tin[it]);
        }
    }

}
vector<vector<int>>criticalConnections(int n, vector<vector<int>>&connections){
    vector<vector<int>>adj(n);
    for(auto it : connections){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int>vis(n,0),tin(n),low(n);
    vector<vector<int>>bridges;
    for(int i=0;i<n;i++){
        if(vis[i]==0) dfs(i,-1,vis,adj,tin,low,bridges);
    }
    return bridges;
}
int main() {
    int n = 4;
    vector<vector<int>> connections = {
        {0, 1}, {1, 2}, {2, 0}, {1, 3}
    };

    
    vector<vector<int>> bridges = criticalConnections(n, connections);

    cout << "Bridges found:\n";
    for (auto &it : bridges) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}
