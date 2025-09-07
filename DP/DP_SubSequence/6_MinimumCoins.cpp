#include<bits/stdc++.h>
using namespace std;
int solve(int ind,int T,vector<int>&arr,vector<vector<int>>&dp){
    if(ind==0){
        if(T%arr[ind]==0){
            return T/arr[ind];
        }else{
            return 1e9;
        }
    }
    if(dp[ind][T]!=-1) return dp[ind][T];

    int nottake = 0+ solve(ind-1,T,arr,dp); // because we are not taking so move forward (ind-1)
    int take =1e9;
    if(arr[ind]<=T){
        take = 1 + solve(ind,T-arr[ind],arr,dp); // we can pick any coins as many as want , so ind in ind
    }

    return dp[ind][T] = min(take,nottake);
}
int minimumCoins(vector<int>&arr,int target){
    int n = arr.size();
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    int ans = solve(n-1,target,arr,dp);
    if(ans >= 1e9){
        return -1;
    }
    return ans;
}
int main(){
    vector<int>arr={1,2,3};
    int target = 7;
    cout<<minimumCoins(arr,target);
}