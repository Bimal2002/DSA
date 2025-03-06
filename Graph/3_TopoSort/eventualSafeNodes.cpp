// #include <bits/stdc++.h>
// using namespace std;

// vector<int> eventualSafeNodes(int V, vector<int> adj[])
// {
//     vector<int> adjRev[V];
//     int indegree[V] = {0};

//     // Reverse the graph edges and calculate indegree
//     for (int i = 0; i < V; i++)
//     {
//         for (auto it : adj[i])
//         {
//             adjRev[it].push_back(i);
//             indegree[i]++;
//         }
//     }

//     // Push nodes with indegree 0 to the queue
//     queue<int> q;
//     vector<int> safeNodes;
//     for (int i = 0; i < V; i++)
//     {
//         if (indegree[i] == 0)
//         {
//             q.push(i);
//         }
//     }

//     // Process nodes in the queue
//     while (!q.empty())
//     {
//         int node = q.front();
//         q.pop();
//         safeNodes.push_back(node);
//         for (auto it : adjRev[node])
//         {
//             indegree[it]--;
//             if (indegree[it] == 0)
//                 q.push(it);
//         }
//     }

//     // Sort the result as required
//     sort(safeNodes.begin(), safeNodes.end());
//     return safeNodes;
// }

// int main()
// {
//     // Graph adjacency list representation
//     vector<int> adj[12] = {{1}, {2}, {3, 4}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10}, {8}, {9}};
//     int V = 12;

//     vector<int> safeNodes = eventualSafeNodes(V, adj);

//     for (auto node : safeNodes)
//     {
//         cout << node << " ";
//     }
//     cout << endl;

//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;


vector<int>eventualSafeNodes(int V,vector<int>adj[]){
        
       vector<int>adjRev[V];
       // reverse the adjList
       int indegree[V]={0};
       for(int i=0;i<V;i++){
        for(auto it : adj[i]){
            adjRev[it].push_back(i);
            indegree[it]++;
        }
       }
}

int main() {

	vector<int> adj[12] = {{1}, {2}, {3, 4}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10},
		{8}, {9}
	};
	int V = 12;
	vector<int> safeNodes = eventualSafeNodes(V, adj);

	for (auto node : safeNodes) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}