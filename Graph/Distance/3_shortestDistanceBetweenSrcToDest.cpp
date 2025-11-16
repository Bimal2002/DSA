#include <bits/stdc++.h>
using namespace std;

vector<int> bfsShortestPath(int n, vector<vector<int>>& adj, int src, int dest) {
    vector<int> dist(n, INT_MAX), parent(n, -1);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == INT_MAX) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);

                if (v == dest)   // early stop
                    break;
            }
        }
    }

    if (dist[dest] == INT_MAX)
        return {};  // no path

    // Reconstruct path src → dest
    vector<int> path;
    for (int v = dest; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int n = 6;
    vector<vector<int>> adj = {
        {1,2},        // 0
        {0,2,3},      // 1
        {0,1,4},      // 2
        {1,4,5},      // 3
        {2,3,5},      // 4
        {3,4}         // 5
    };

    int src = 0, dest = 5;

    vector<int> path = bfsShortestPath(n, adj, src, dest);

    if (path.empty())
        cout << "No path!\n";
    else {
        cout << "Shortest distance = " << path.size() - 1 << "\nPath: ";
        for (int x : path) cout << x << " ";
    }
}
