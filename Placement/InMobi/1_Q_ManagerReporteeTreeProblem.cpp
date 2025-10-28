// Problem Overview
// The organizational structure described (Employee 1 is the CEO, everyone else has exactly one manager) forms a tree structure, with the CEO (ID 1) as the root. The task is to find the total count of subordinates for every employee. In graph theory terms, this means finding the size of the subtree rooted at each node, and then subtracting 1 (since the employee themselves isn't their own reportee).

// Approach: Depth-First Search (DFS)The most efficient way to solve this is with a single pass of Depth-First Search (DFS), which has a time complexity of $O(N)$, where $N$ is the number of employees.Build the Tree: The input gives a reportee-manager relationship ($n1 \rightarrow n2$). We must convert this into a manager-reportee adjacency list structure ($n2 \rightarrow n1$ children) to easily traverse the tree downwards from the root.DFS Traversal: We use a recursive DFS function, starting at the CEO (ID 1).Subtree Size Calculation: For any given employee $u$, the DFS function recursively calls itself for all of $u$'s direct reportees ($v_1, v_2, \ldots$). The size of the subtree rooted at $u$ is simply 1 (for $u$ itself) + the sum of all subtree sizes of its direct reportees.Store Result: Before the DFS function returns the total subtree size, we calculate the final count of reportees for $u$: $\text{Reportees}[u] = \text{Subtree Size}[u] - 1$.    



#include <bits/stdc++.h>
using namespace std;

// Global variables for simplicity in recursion
vector<vector<int>> adj; // Adjacency list: manager -> direct reportees
vector<int> reportee_counts; // Stores the final result for each employee

int dfs(int u) {
    // Start by counting 'u' itself
    int subtree_size = 1;

    // Recursively visit all direct reportees (children)
    for (int v : adj[u]) {
        subtree_size += dfs(v);
    }

    // The total number of reportees is the subtree size minus 'u' itself.
    reportee_counts[u] = subtree_size - 1;

    // Return the full subtree size to the parent node
    return subtree_size;
}

int main() {

    int N;
    // Read the total number of employees N (up to 1e5)
    if (!(std::cin >> N)) return 1;

    // Resize vectors for 1-based indexing (IDs 1 to N)
    adj.resize(N + 1);
    reportee_counts.resize(N + 1);

    // Read the N-1 lines of manager relationships
    // Input is: reportee_id manager_id
    for (int i = 0; i < N - 1; ++i) {
        int reportee_id, manager_id;
        if (!(std::cin >> reportee_id >> manager_id)) return 1;
        
        // Build the tree structure: manager_id points to reportee_id
        adj[manager_id].push_back(reportee_id);
    }

    // Start the DFS from the CEO, Employee ID 1 (the root of the tree)
    dfs(1);

    // Print the final output: N space-separated integers
    for (int i = 1; i <= N; ++i) {
        cout << reportee_counts[i] << (i == N ? "" : " ");
    }
    cout << "\n";

    return 0;
}