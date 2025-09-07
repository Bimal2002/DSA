#include<bits/stdc++.h>
using namespace std;
bool solve(int ind , vector<int>&arr,int k,vector<vector<int>>&dp){
    if(k==0) return true;
    if(ind ==0 ) return arr[ind] == k;
    if(dp[ind][k] !=-1) return dp[ind][k];
    bool nottake = solve(ind-1,arr,k,dp);
    bool take = false;
    if(arr[ind]<= k){
        take = solve(ind-1,arr,k-arr[ind],dp);
    }

    return dp[ind][k] =take || nottake;
}
bool PartitionEqualSum(vector<int>&arr){
    int s =0;
    int n  = arr.size();
    for(int i=0;i<arr.size();i++){
        s += arr[i];
    }
    int k = s/2;
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    if(s%2){ // if odd then partion is not possible
        return false;

    }else{
        return solve(n-1,arr,k,dp);
    }
}
int main(){
    vector<int>arr={2,3,3,3,4,5};
    if(PartitionEqualSum(arr)){
        cout<<"Possible";
    }else{
        cout<<"Not Possible";
    }
}