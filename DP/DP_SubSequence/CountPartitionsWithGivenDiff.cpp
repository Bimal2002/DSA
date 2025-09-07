#include<bits/stdc++.h>
using namespace std;
int cntWays(int ind,int target,vector<int>&arr,vector<vector<int>>&dp){
    
    if(ind==0){
        if(target == 0 && arr[ind]==0){
            return 2;
        }
        else if(target ==0 || arr[ind]==target){
            return 1;
        }else{
            return 0;
        }
    }

    int nottake = cntWays(ind-1,target,arr,dp);
    int take =0;
    if(arr[ind]<= target){
        take = cntWays(ind-1,target-arr[ind],arr,dp);
    }
    return dp[ind][target] = take + nottake;
}
int countPartitions(int d, vector<int>&arr){
    int n = arr.size();
    int totSum =0;
    for(int i=0;i<n;i++){
        totSum += arr[i];
    }

    if(totSum-d<0) return 0;
    if((totSum-d)%2==1) return 0;
    int s2 = (totSum-d)/2;
    vector<vector<int>>dp(n,vector<int>(s2+1,-1));
    return cntWays(n-1,s2,arr,dp);

}
int main(){
    vector<int> arr = {5,2,6,4};
    int d=3;

    cout<<"The number of subsets found are " <<countPartitions(d,arr);

}