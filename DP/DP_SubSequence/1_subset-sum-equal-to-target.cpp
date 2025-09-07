#include<bits/stdc++.h>
using namespace std;
bool sumutils(int ind , int target ,vector<vector<int>>&dp,vector<int>&arr){
    if(target == 0)return true;
    if(ind==0) return target == arr[ind];
    if(dp[ind][target]!=-1) return dp[ind][target];
    bool notTaken = sumutils(ind-1,target,dp,arr);
    bool taken = false;
    if(arr[ind]<= target){
           taken = sumutils(ind-1,target - arr[ind],dp,arr);
    }

    return dp[ind][target] = taken || notTaken;
}
bool subsetSumToK(vector<int>&arr,int k){
    int n = arr.size();
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return sumutils(n-1,k,dp,arr);
}
// tabulation 
bool subsetSumToKTab(vector<int>&arr,int k){
    int n = arr.size();
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    for(int i=0;i<n;i++) dp[i][0] = true;
    dp[0][arr[0]]= true;

    for(int i=1;i<n;i++){
        for(int target =0 ; target <=k;target++){
            bool nottake = dp[i-1][target];
            bool take = false;
            if(target >= arr[i]){
                take = dp[i-1][target-arr[i]];
            }

            dp[i][target] = take || nottake;
            
        }
    }
    return dp[n-1][k];
}
int main(){
    vector<int>arr ={1,2,3,4};
    int k=4;
    int n = arr.size();
    if(subsetSumToK(arr,k)){
        cout<<"Target found ";
    }else{
        cout<<"Not Found";
    }
    cout<<endl;
    cout<<"Tabulation ans "<<endl;
    if(subsetSumToKTab(arr,k)){
        cout<<"Target found";
    }else{
        cout<<"Not found";
    }

}