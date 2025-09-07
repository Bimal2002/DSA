#include<bits/stdc++.h>
using namespace std;
int solve(int ind,int target,vector<int>&arr,vector<vector<int>>&dp){
    if(ind==0){
        return target % arr[0] == 0;
    }
    if(dp[ind][target]!=-1) return dp[ind][target];
    int nottake = solve(ind-1,target,arr,dp);
    int take =0;
    if(arr[ind] <= target){
         take = solve(ind,target-arr[ind],arr,dp);
    }

    return dp[ind][target] = take + nottake;

}
int countways(vector<int>&arr,int T){
    int n = arr.size();
    vector<vector<int>>dp(n,vector<int>(T+1,-1));
    return solve(n-1,T,arr,dp);
}
int main(){
    vector<int>arr={1,2,3};
    int T =4;
    int ans = countways(arr,T);
    cout<<ans;
}