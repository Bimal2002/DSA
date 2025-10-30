#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> times) {
    sort(times.begin(), times.end());
    const int PROCESS_TIME = 300; // 5 minutes = 300 seconds
    const int MAX_WAIT = 10;
    
    queue<int> q;
    int finishTime = 0;
    
    for (int t : times) {
        // Process queue until reactor idle or until next arrival
        while (!q.empty() && finishTime + PROCESS_TIME <= t) {
            finishTime += PROCESS_TIME;
            q.pop();
        }

        if (finishTime <= t) {
            // Reactor is idle -> start immediately
            finishTime = t + PROCESS_TIME;
        } 
        else if (q.size() < MAX_WAIT) {
            // Reactor busy -> add to cooling chamber
            q.push(t);
        } 
        else {
            // Chamber full -> reject
            continue;
        }
    }

    // Process remaining samples in queue
    while (!q.empty()) {
        finishTime += PROCESS_TIME;
        q.pop();
    }

    return finishTime;
}

int main() {
    vector<int> times1 = {1, 6, 9, 502};
    cout << solution(times1) << endl; // 1201

    vector<int> times2 = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    cout << solution(times2) << endl; // 3601

    return 0;
}
