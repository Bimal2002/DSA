#include <bits/stdc++.h>
using namespace std;

// bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]) {
//     vis[node] = 1;
//     pathVis[node] = 1;

//     // traverse for adjacent nodes
//     for (auto it : adj[node]) {
//         // when the node is not visited
//         if (!vis[it]) {
//             if (dfsCheck(it, adj, vis, pathVis) == true)
//                 return true;
//         }
//         // if the node has been previously visited
//         // but it has to be visited on the same path
//         else if (pathVis[it]) {
//             return true;
//         }
//     }

//     pathVis[node] = 0;
//     return false;
// }

// Function to detect cycle in a directed graph.
// bool isCyclic(int V, vector<int> adj[]) {
//     int vis[V] = {0};
//     int pathVis[V] = {0};

//     for (int i = 0; i < V; i++) {
//         if (!vis[i]) {
//             if (dfsCheck(i, adj, vis, pathVis) == true) return true;
//         }
//     }
//     return false;
// }
bool dfsCheck(int node ,vector<int>adj[], int vis[],int pathVis[]){
    vis[node]=1;
    pathVis[node]=1;
    for(auto it : adj[node]){
        if(!vis[it]){
            if(dfsCheck(it,adj,vis,pathVis)==true) return true;
        }
        else if(pathVis[it]){
            return true;
        }
    }
    return false;
}


bool bfs(int node,vector<int>adj[],int vis[]){
    vis[node]=1;
    queue<pair<int,int>>q;
    q.push({node,-1});

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto adjNode : adj[node]){
            if(!vis[adjNode]){
                vis[adjNode]= 1;
                q.push({adjNode,node});
            }
            else if(adjNode != parent){
                return true;
            }
        }
    }
    return false;
}
bool isCyclic(int V,vector<int>adj[]){
     int vis[V]={0};
     int pathVis[V]={0};
     for(int i=0;i<V;i++){
        // if(!vis[i]){
        //     if(dfsCheck(i,adj,vis,pathVis)== true) return true;
        // }

        if(!vis[i]){
            if(bfs(i,adj,vis)==true) return true;
        }
     }
     return false;
}
// Function to add an edge to the graph
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

int main() {
    // V = 11, E = 11;
    vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
    int V = 11;

    bool ans = isCyclic(V, adj);

    if (ans)
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}
