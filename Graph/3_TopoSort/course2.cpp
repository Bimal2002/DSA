#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int>isPossible(int V, vector<pair<int, int> >& prerequisites) {
		vector<int> adj[V];
		for (auto it : prerequisites) {
			adj[it.first].push_back(it.second);
		}



		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		// if (topo.size() == V) return true;
		// return false;
        return topo;


	}
};

int main() {

	vector<pair<int, int>> prerequisites;
	int N = 4;
	prerequisites.push_back({1, 0});
	prerequisites.push_back({2, 1});
	prerequisites.push_back({3, 2});

	Solution obj;
	vector<int>topo = obj.isPossible(N, prerequisites);

    if (topo.size() == N){
        cout<<"YES"<<endl;
        for(auto it : topo){
            cout<<it<<" ";
        }
    }else{
      cout<<"NO"<<endl;
    }
	cout << endl;

	return 0;
}