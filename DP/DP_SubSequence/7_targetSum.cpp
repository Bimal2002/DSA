#include<bits/stdc++.h>
using namespace std;
int solve(int ind,int target,vector<int>&arr,vector<vector<int>>&dp){
    if(ind==0){
        if(target==0 && arr[ind]==0){
            return 2;
        }else if(target ==0 || arr[ind]==target){
            return 1;
        }else{
            return 0;
        }
    }
    if(dp[ind][target]!=-1) return dp[ind][target];
    int nottake = 0 + solve(ind-1,target,arr,dp);
    int take =0;
    if(arr[ind]<=target) take = 1+ solve(ind-1,target-arr[ind],arr,dp);
    
    return dp[ind][target] =  take + nottake;
}
int targetSum(vector<int>&arr,int k){ 
    int n = arr.size();
    int totSum =0;
    for(int i=0;i<n;i++){
        totSum += arr[i];
    }
    if(totSum-k <0) return -1;
    if((totSum-k)%2==1) return -1;
    int s2 = (totSum-k)/2;
    vector<vector<int>>dp(n,vector<int>(s2+1,-1));
    return solve(n-1,s2,arr,dp);
}
int main(){
    vector<int>arr={1,2,3,1};
    int k = 3;
    int ans = targetSum(arr,k);
    cout<<ans;
}