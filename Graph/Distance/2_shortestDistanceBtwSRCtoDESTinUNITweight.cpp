#include <bits/stdc++.h>
using namespace std;

// BFS to find shortest path length from src to dest
int shortestPath(vector<vector<int>>& adjList, int src, int dest,vector<int>&parent) {
    int n = adjList.size();
    vector<int> dist(n, INT_MAX);
    queue<int> q;

    dist[src] = 0;
    parent[src]=-1; // src has no parent
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adjList[u]) {
            if (dist[u]+1 < dist[v]) { 
            // if(dist[v]==INT_MAX){
                dist[v] = dist[u] + 1;
                q.push(v);
                parent[v]=u;

                if (v == dest)
                    return dist[v]; // early stop if reached
            }
        }
    }

    return -1; // no path
}
void printPath(vector<int>&parent,int src,int dest){
    vector<int>path;
    for(int v = dest;v!=-1;v=parent[v]){
        path.push_back(v);
    }
    reverse(path.begin(),path.end());
    cout<<"Path: ";
    for(int i=0;i<path.size();i++){
        cout<<path[i];
        if(i<path.size()-1) cout<<"->";
    }
    cout<<endl;
}
int main() {
    // Example adjacency matrix (undirected graph)
    vector<vector<int>> adjMatrix = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 1},
        {0, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 1, 0}
    };

    int src = 0, dest = 5;

    // Step 1: Convert matrix → list
    int n = adjMatrix.size();
    vector<vector<int>>adj(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adjMatrix[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int>parent(adj.size(),-1);
    // Step 2: Find shortest path
    int result = shortestPath(adj, src, dest,parent);

    if (result != -1)
        cout << "\nShortest path length from " << src << " to " << dest << " is: " << result << endl;
    else
        cout << "\nNo path exists between " << src << " and " << dest << endl;
    printPath(parent,src,dest);    

    return 0;
}
