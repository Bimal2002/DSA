#include<bits/stdc++.h>
using namespace std;
int waysUtils(int ind ,int k, vector<int>&arr,vector<vector<int>>&dp){
    if(k==0) dp[ind][k]=1;
    if(ind==0) dp[ind][k] = (arr[ind]==k)?1:0;

    if(dp[ind][k]!=-1) return dp[ind][k];

    int nottake = waysUtils(ind-1,k,arr,dp);
    int take =0 ;
    if(arr[ind]<= k){
        take =waysUtils(ind-1,k-arr[ind],arr,dp);
    }
    return dp[ind][k] = take+ nottake;

}
int countSubsetsWithSumK(vector<int>&arr,int k){
     int n = arr.size();
     vector<vector<int>>dp(n,vector<int>(k+1,-1));
     return waysUtils(n-1,k,arr,dp);
}
int main(){
    vector<int>arr={1,2,3};
    int k = 3;
    cout<<countSubsetsWithSumK(arr,k);
}