/*
Problem Statement (Reconstructed)

You are given three arrays of equal length N:

ids[i] → unique process ID

priorities[i] → priority of each process
(lower number ⇒ higher priority)

processingTime[i] → time needed to complete the process

and a total available time = maxTime.

You need to return a vector of ids representing which processes can be completed within the available time,
assuming you always execute higher-priority processes first (lower priority value = higher priority).

If there’s a tie in priority, you can pick the shorter process first.

*/
#include<bits/stdc++.h>
using namespace std;
vector<int>completedProcesses(vector<int>ids, vector<int>priorities, vector<int>processing, int maxTime){
       int n = ids.size();
       vector<vector<int>> arr(n, vector<int>(3));
       for(int i=0;i<n;i++){
          arr[i][0] = priorities[i];
          arr[i][1] = processing[i];
          arr[i][2] =  ids[i];
       }
       sort(arr.begin(),arr.end(),[](vector<int>&a,vector<int>&b){
           if(a[0]!=b[0]) return a[0] < b[0];
           if(a[1]!= b[1]) return a[1]<b[1];
           return a[2] < b[2];
       });
       
       vector<int>result;
       int time =0;
       for(int i=0;i<arr.size();i++){
           int t = arr[i][1];
           if(t+time < maxTime){
            result.push_back(arr[i][2]);
           }else{
            break;
           }
       }

       return result;

}
int main() {
    vector<int> ids = {1, 2, 3, 4};
    vector<int> priorities = {3, 1, 2, 1};
    vector<int> processing = {4, 2, 3, 1};
    int maxTime = 5;

    vector<int> res = completedProcesses(ids, priorities, processing, maxTime);
    for (int id : res) cout << id << " ";
}