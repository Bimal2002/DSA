#include <bits/stdc++.h>
using namespace std;

int getMinLag(int max_edges, int network_nodes, vector<int> network_from, 
              vector<int> network_to, vector<int> network_weight) {
    
    int n = network_nodes;
    int m = network_from.size();
    
    // Build adjacency list
    vector<vector<pair<int, int>>> adj(n); // adj[u] = {(v, weight)}
    for (int i = 0; i < m; i++) {
        adj[network_from[i]].push_back(make_pair(network_to[i], network_weight[i]));
    }
    
    // Priority queue: pair<lag, pair<edges_used, node>>
    // Min heap based on lag
    priority_queue<pair<int, pair<int, int>>, 
                   vector<pair<int, pair<int, int>>>, 
                   greater<pair<int, pair<int, int>>>> pq;
    
    // dist[node][edges_used] = minimum lag to reach node with edges_used edges
    vector<vector<int>> dist(n, vector<int>(max_edges + 1, INT_MAX));
    
    // Start from node 0 with 0 edges and 0 lag
    // pq.push(make_pair(0, make_pair(0, 0)));
    pq.push({0,{0,0}});
    dist[0][0] = 0;
    
    while (!pq.empty()) {
        pair<int, pair<int, int>> current = pq.top();
        pq.pop();
        
        int lag = current.first;
        int edges_used = current.second.first;
        int u = current.second.second;
        
        // If we reached destination
        if (u == n - 1) {
            return lag;
        }
        
        // Skip if we've found a better path to this state
        if (lag > dist[u][edges_used]) {
            continue;
        }
        
        // Can't use more edges
        if (edges_used >= max_edges) {
            continue;
        }
        
        // Explore neighbors
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            int new_lag = max(lag, w);
            int new_edges = edges_used + 1;
            
            // Only process if this gives a better lag
            if (new_lag < dist[v][new_edges]) {
                dist[v][new_edges] = new_lag;
                pq.push(make_pair(new_lag, make_pair(new_edges, v)));
            }
        }
    }
    
    // Find minimum lag to reach n-1 with any number of edges <= max_edges
    int result = INT_MAX;
    for (int i = 0; i <= max_edges; i++) {
        result = min(result, dist[n - 1][i]);
    }
    
    return (result == INT_MAX) ? -1 : result;
}

int main() {
    // Example test case
    int n = 4, m = 5, max_edges = 2;
    vector<int> network_from = {0, 1, 0, 2, 1};
    vector<int> network_to = {1, 3, 2, 3, 2};
    vector<int> network_weight = {5, 6, 6, 5, 5};
    
    int result = getMinLag(max_edges, n, network_from, network_to, network_weight);
    cout << "Minimum lag: " << result << endl;
    
    return 0;
}