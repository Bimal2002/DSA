#include <bits/stdc++.h>
using namespace std;

vector<int> happiness;
vector<vector<int>> adj;
vector<int> visited;
int dest;
long long answer = LLONG_MIN;

long long maxSubarray(vector<int>& arr) {
    long long best = LLONG_MIN, cur = 0;
    for (int x : arr) {
        cur = max((long long)x, cur + x);
        best = max(best, cur);
    }
    return best;
}

void dfs(int node, vector<int>& path) {
    if (node == dest) {
        answer = max(answer, maxSubarray(path));
        return;
    }

    visited[node] = 1;

    for (int nxt : adj[node]) {
        if (!visited[nxt]) {
            path.push_back(happiness[nxt]);
            dfs(nxt, path);
            path.pop_back();
        }
    }

    visited[node] = 0;
}

int main() {
    int n, m, start; 
    cin >> n >> m >> start >> dest;
    happiness.resize(n);
    for(int i=0;i<n;i++) cin >> happiness[i];

    adj.assign(n, {});
    for(int i=0;i<m;i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visited.assign(n,0);
    vector<int> path = { happiness[start] };

    dfs(start, path);

    cout << answer << endl;
}
