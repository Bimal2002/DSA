#include <bits/stdc++.h>
using namespace std;

int batterySchedule(vector<int>& capacity, int recharge) {
    int n = capacity.size();
    vector<long long> availableAt(n, 0); // when each battery is available again
    long long time = 0;
    unordered_set<int> used; // track distinct batteries used

    // Use a min-heap to always get the battery available the earliest
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    // initially, all batteries available at time 0
    for (int i = 0; i < n; i++) pq.push({0, i});

    while (time < recharge) {
        // get next available battery
        auto cur = pq.top(); pq.pop();
        long long avail = cur.first;
        int id = cur.second;

        // if all batteries are still recharging
        if (avail > time) return -1;

        used.insert(id);

        long long useTime = min((long long)capacity[id], (long long)recharge - time);
        time += useTime;

        // this battery will recharge and be available again after recharge minutes
        pq.push({time + recharge, id});
    }

    return used.size();
}

int main() {
    vector<int> c1 = {3, 5, 4};
    int T1 = 10;
    cout << batterySchedule(c1, T1) << endl; // Output: 3

    vector<int> c2 = {3, 3};
    int T2 = 10;
    cout << batterySchedule(c2, T2) << endl; // Output: -1

    vector<int> c3 = {2, 4, 3, 5};
    int T3 = 12;
    cout << batterySchedule(c3, T3) << endl; // Output: 4

    return 0;
}
