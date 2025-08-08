#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findOrder(vector<string> &words) {
        vector<int> graph[26];
        vector<int> indegree(26, 0);
        vector<bool> exists(26, false);

        // Mark which characters exist
        for (string& word : words) {
            for (char ch : word) {
                exists[ch - 'a'] = true;
            }
        }

        // Build graph
        for (int i = 0; i + 1 < words.size(); i++) {
            string w1 = words[i], w2 = words[i + 1];
            int len = min(w1.length(), w2.length());
            int j = 0;
            while (j < len && w1[j] == w2[j]) j++;
            if (j < len) {
                int u = w1[j] - 'a';
                int v = w2[j] - 'a';
                graph[u].push_back(v);
                indegree[v]++;
            } else if (w1.length() > w2.length()) {
                // invalid case like ["abc", "ab"]
                return "";
            }
        }

        // Topological Sort (Kahn's algorithm)
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (exists[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        string res = "";
        while (!q.empty()) {
            int u = q.front(); q.pop();
            res += (char)(u + 'a');
            for (int v : graph[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // If any existing character still has indegree > 0, there's a cycle
        for (int i = 0; i < 26; i++) {
            if (exists[i] && indegree[i] != 0) {
                return "";
            }
        }

        return res;
    }
};

// Driver code
int main() {
    vector<string> words1 = {"baa", "abcd", "abca", "cab", "cad"};
    Solution sol;
    string order1 = sol.findOrder(words1);

    if (order1 == "") {
        cout << "Invalid Order (Cycle or Conflict Detected)" << endl;
    } else {
        cout << "Alien Dictionary Order: " << order1 << endl;
    }

    // You can test more cases
    vector<string> words2 = {"caa", "aaa", "aab"};
    string order2 = sol.findOrder(words2);
    cout << "Alien Dictionary Order: " << (order2 == "" ? "Invalid" : order2) << endl;

    vector<string> words3 = {"ab", "cd", "ef", "ad"};
    string order3 = sol.findOrder(words3);
    cout << "Alien Dictionary Order: " << (order3 == "" ? "Invalid" : order3) << endl;

    return 0;
}
