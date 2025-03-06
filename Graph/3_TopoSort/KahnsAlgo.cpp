#include <bits/stdc++.h>
using namespace std;

vector<int>topoSort(int V,vector<int>adj[]){
    int indegree[V]={0};
    for(int i=0;i<V;i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    queue<int>q;
    vector<int>topo;
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }

    return topo;
    
}
int main() {
    // Define the graph
    vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    int V = 6;

    // Perform topological sort
    vector<int> ans = topoSort(V, adj);

    // Print the result
    for (auto node : ans) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
