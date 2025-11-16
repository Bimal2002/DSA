/*
Question 1: Maximise sum

You are given:

An integer array A of length N

An integer K

Task

For each index i (1 ≤ i ≤ N),
determine the maximum sum that can be obtained by using at most K elements from the subarray A[1..i].

Notes

1-based indexing

A subarray is contiguous.

Example (as shown):
If array = [1,2,3], subarrays are [1], [2], [3], [1,2], [2,3], [1,2,3].

*/


#include<bits/stdc++.h>
using namespace std;
vector<long long> maxSumAtMostK(vector<int>& A, int K){
    int N = A.size();
    vector<long long >result(N,0);
    int l =0, r= 0;
    long long window = 0;
    long long best =0;
    while(r<N){
        window += A[r];
        if(r-l+1>K){
            window -= A[l];
            l--;
        }
        long long currBest = max(window,(long long)A[r]);
        best = max(best,currBest);
        result[r]= best;
        r++;
    }
    return result;
    
}
int main(){
    int n ,K;
    cin>>n>>K;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
       cin>>arr[i];
    }
    vector<long long>ans = maxSumAtMostK(arr,K);
    for(long long num : ans){
        cout<<num<< " ";
    }

}