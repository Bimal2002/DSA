#include <bits/stdc++.h>
using namespace std;

int minTimeToFinishTasks(vector<int>& mem, vector<int>& type, int maxMemory) {
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < mem.size(); i++)
        mp[type[i]].push_back(mem[i]);
    
    int totalTime = 0;
    for (auto& it : mp) {
        vector<int>arr = it.second;
        sort(arr.rbegin(), arr.rend());
        int i = 0;
        while (i < arr.size()) {
            if (i + 1 < arr.size() && arr[i] + arr[i+1] <= maxMemory) {
                totalTime++;
                i += 2;
            } else {
                totalTime++;
                i++;
            }
        }
    }
    return totalTime;
}

int main() {
    vector<int> taskMemory = {1, 4, 5, 2, 3};
    vector<int> taskType = {1, 2, 1, 3, 4};
    int maxMemory = 6;
    cout << minTimeToFinishTasks(taskMemory, taskType, maxMemory);
    return 0;
}
