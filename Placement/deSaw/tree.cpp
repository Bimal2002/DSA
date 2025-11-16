/*
We are given:

A tree (undirected connected graph with n nodes and n-1 edges).

Each node has a color (0 = white, 1 = black).

We can add exactly one extra edge between any two nodes.

We must count how many such pairs (u, v) will create a perfect route cycle, defined as:
1️⃣ The cycle length ≥ 3
2️⃣ All nodes in the cycle have the same color


*/


#include <bits/stdc++.h>
using namespace std;

long countRouteCycles(int n, vector<int> from, vector<int> to, vector<int> color) {
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < from.size(); i++) {
        adj[from[i]].push_back(to[i]);
        adj[to[i]].push_back(from[i]);
    }

    vector<int> vis(n + 1, 0);
    long ans = 0;

    function<void(int,int,int&,int)> dfs = [&](int node, int col, int &size, int parent) {
        vis[node] = 1;
        size++;
        for (int nei : adj[node]) {
            if (!vis[nei] && color[nei - 1] == col)
                dfs(nei, col, size, node);
        }
    };

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int size = 0;
            dfs(i, color[i - 1], size, -1);
            if (size >= 3) {
                long totalPairs = 1L * size * (size - 1) / 2; // total possible connections
                long existingEdges = size - 1;                // already connected in tree
                ans += (totalPairs - existingEdges);
            }
        }
    }

    return ans;
}

int main() {
    int tree_nodes = 6;
    vector<int> tree_from = {1, 2, 2, 1, 5};
    vector<int> tree_to   = {2, 3, 4, 5, 6};
    vector<int> colors    = {0, 1, 1, 1, 0, 0};

    cout << countRouteCycles(tree_nodes, tree_from, tree_to, colors) << endl;
    return 0;
}
