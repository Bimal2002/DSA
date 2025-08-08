#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstraUsingPriorityQueue(int V, vector<vector<int>> adj[], int S)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {dist,node}
    vector<int> dist(V, 0);
    for (int i = 0; i < V; i++)
    {
        dist[i] = 1e9;
    }
    dist[S] = 0;
    pq.push({0, S});
    while (!pq.empty())
    {

        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        for (auto it : adj[node])
        {
            int adjN = it[0];
            int wt = it[1];
            if (dis + wt < dist[adjN])
            {
                dist[adjN] = dis + wt;
                pq.push({dis + wt, adjN});
            }
        }
    }
    return dist;
}
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    set<pair<int, int>> st;
    vector<int> dist(V, 1e9);
    st.insert({0, S});
    dist[S] = 0;
    while (!st.empty())
    {
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase({dis, node});
        for (auto edge : adj[node])
        {
            int nodeN = edge[1];
            int nodeW = edge[0];
            if (dis + nodeW < dist[nodeN])
            {
                if (dist[nodeN] != 1e9)
                {
                    st.erase({nodeW, nodeN});
                }

                dist[nodeN] = dis + nodeW;
                st.insert({dist[nodeN], nodeN});
            }
        }
    }

    return dist;
}

int main()
{
    int V = 3, S = 2;
    vector<vector<int>> adj[V];

    adj[0].push_back({1, 1}); // Edge from 0 to 1 with weight 1
    adj[0].push_back({6, 2}); // Edge from 0 to 2 with weight 6
    adj[1].push_back({3, 2}); // Edge from 1 to 2 with weight 3
    adj[1].push_back({1, 0}); // Edge from 1 to 0 with weight 1
    adj[2].push_back({3, 1}); // Edge from 2 to 1 with weight 3
    adj[2].push_back({6, 0}); // Edge from 2 to 0 with weight 6

    vector<int> res = dijkstra(V, adj, S);

    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
