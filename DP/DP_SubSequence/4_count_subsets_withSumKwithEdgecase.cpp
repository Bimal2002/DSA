#include<bits/stdc++.h>
using namespace std;
int waysUtils(int ind,int target,vector<int>&arr,vector<vector<int>>&dp){
    // if(target==0) return dp[ind][target]=1;
    // if(ind==0) return dp[ind][target] ==(arr[ind]==target)?1:0;
    if(ind ==0 ){
        if(target==0 && arr[0]==0)return 2;
        else if(target==0 || arr[0]==target) return 1;
        else return 0;
    }

    if(dp[ind][target]!=-1) return dp[ind][target];
    int nottake = waysUtils(ind-1,target,arr,dp);
    int take = 0;
    if(arr[ind]<= target) take = waysUtils(ind-1,target-arr[ind],arr,dp);

    return dp[ind][target] = take+ nottake;
}
int countWays(vector<int>&arr,int k){
    int n = arr.size();
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return waysUtils(n-1,k,arr,dp);
}
int main(){
    vector<int>arr={0,0,1};
    int k=1;
    int ans = countWays(arr,k);
    cout<<ans;
}