#include<bits/stdc++.h>
using namespace std;
int timer = 0;
void dfs(int node,int parent,vector<vector<int>>&adj,vector<int>&vis,vector<int>&low,vector<int>&tin,vector<int>&ariticulations){
    vis[node]=1;
    low[node]= tin[node]=timer;
    int childCount =0;

    for(auto it : adj[node]){
        if(it == parent) continue;
 
        if(!vis[it]){
            dfs(it,node,adj,vis,low,tin,ariticulations);
            low[node] = min(low[node],tin[it]);
            
            if(parent!=-1 && low[it] >= tin[node]){
                 ariticulations[node]=1;
            }

            childCount++;

        }else{
            low[node] = min(low[node],tin[it]);
        }
    }
    if(parent == -1 && childCount > 1){
        ariticulations[node]=1;
    }

}
vector<int>articulationPoints(int n, vector<vector<int>>&connections){
    vector<vector<int>>adj(n);
    for(auto it : connections){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int>vis(n,0),tin(n),low(n),ariticulations(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,-1,adj,vis,low,tin,ariticulations);
        }
    }
    vector<int>ans;
    for(int i=0;i<n;i++){
       if(ariticulations[i]==1){
        ans.push_back(i);
       }
    }
    return ans;

}
int main() {
    int n = 4;
    vector<vector<int>> connections = {
        {0, 1}, {1, 2}, {2, 0}, {1, 3}
    };
    
    vector<int> points = articulationPoints(n, connections);

    cout << "Articulation Points:\n";
    for (auto it : points) cout << it << " ";
    cout << endl;

    return 0;
}