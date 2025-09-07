#include<bits/stdc++.h>
using namespace std;
bool targetSum(int ind,int k,vector<vector<int>>&dp , vector<int>&arr){
    if(k==0) dp[ind][0]= true;
    if(ind == 0) dp[ind][k] =(arr[0]==k);

    if(dp[ind][k]!=-1) return dp[ind][k];

    bool nottake = targetSum(ind-1,k,dp,arr);
    bool take = false;
    if(arr[ind]<=k) take = targetSum(ind-1,k-arr[ind],dp,arr);

    return dp[ind][k] =take || nottake;
}
int minDiff(vector<int>&arr){
    int n =arr.size();
    int totSum=0;
    for(int i=0;i<arr.size();i++){
        totSum += arr[i];
    }
    vector<vector<int>>dp(n,vector<int>(totSum+1,-1));
    for(int i=0;i<=totSum;i++){
         targetSum(n-1,i,dp,arr);
    }

    int mini =INT_MAX;
    for(int i=0;i<totSum;i++){
       if(dp[n-1][i] == true){ // dp[n-1] row give us idea which sum is present from i=0 to totSum . then only present sum , calculate the mini difference 
        int diff = abs(i-(totSum-i));
        mini = min(mini,diff);
       }
    }
    return mini;

}
int main(){
    vector<int>arr={1,2,3,9};
    
    int ans = minDiff(arr);
    cout<<ans;
}