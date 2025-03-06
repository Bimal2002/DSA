#include<bits/stdc++.h>
using namespace std;
vector<int>bellman_ford(int V,vector<vector<int>>&edges,int S){
    vector<int>dist(V,1e9);
    dist[S]=0; // distance from source to source is 0
    for(int i=0;i<V-1;i++){
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u] != 1e9 && dist[u]+wt < dist[v]){
                dist[v]= dist[u]+wt;
            }

        }
    }

    // check for N-th steps 
    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int wt =it [2];

        if(dist[u]!=1e9 && dist[u]+wt < dist[v]){
            
            // if in Nth node also it take update that means there must be a negative cycle  formation because there are total V verties , so V-1 edges . so for updating all the nodes properly it will take V-1 for loop , if in Nth loop also it take update that means there mjust a cycle

            return {-1};
        }
        return dist;
    }
}
int main() {

	int V = 6;
	vector<vector<int>> edges(7, vector<int>(3));
	edges[0] = {3, 2, 6};
	edges[1] = {5, 3, 1};
	edges[2] = {0, 1, 5};
	edges[3] = {1, 5, -3};
	edges[4] = {1, 2, -2};
	edges[5] = {3, 4, -2};
	edges[6] = {2, 4, 3};

	int S = 0;
	vector<int> dist = bellman_ford(V, edges, S);
	for (auto d : dist) {
		cout << d << " ";
	}
	cout << endl;

	return 0;
}