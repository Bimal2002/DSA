// There are n cities and m edges connected by some number of flights. You are given an array of flights where flights[i] = [ fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost price. You have also given three integers src, dst, and k, and return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
#include <bits/stdc++.h>
using namespace std;
int CheapestFLight(int n, vector<vector<int>> flights, int src, int dst, int K)
{

    // convert 2d vector matrix( adj matrix) to AdjList
    vector<pair<int, int>> adj[n];
    for (auto it : flights)
    {
        adj[it[0]].push_back({it[1], it[2]});
        // adj[it[1]].push_back({it[2],it[1]});
    }
    // here we are uisng QUEUE instead of Priority Queue because we want to find the cheapest flight within the K stops not shortest distance flight .
    queue<pair<int, pair<int, int>>> q; // {steps,{node,distance}}
    vector<int> dist(n, 1e9);
    dist[src] = 0;
    q.push({0, {src, 0}});
    while (!q.empty())
    {
        int stops = q.front().first;
        int node = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();

        if (stops > K)
        {
            continue;
        }
        for (auto iter : adj[node])
        {
            int adjNode = iter.first;
            int edw = iter.second;

            if (cost + edw < dist[adjNode])
            {
                dist[adjNode] = cost + edw;
                q.push({stops + 1, {adjNode, cost + edw}});
            }
        }
    }
    if (dist[dst] == 1e9)
    {
        return -1;
    }
    return dist[dst];
}


int main()
{
    // Driver Code.
    int n = 4, src = 0, dst = 3, K = 1;

    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};

    int ans = CheapestFLight(n, flights, src, dst, K);

    cout << ans;
    cout << endl;

    return 0;
}