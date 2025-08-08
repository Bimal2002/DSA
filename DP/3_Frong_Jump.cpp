#include<bits/stdc++.h>
using namespace std;
int func(vector<int>& arr,int ind){
     //base case
     if(ind ==0) return 0;
     int jumpOne = func(arr,ind-1)+ abs(arr[ind]-arr[ind-1]);
     int jumpTwo=INT_MAX;
     if(ind>1){
        jumpTwo = func(arr,ind-2) + abs(arr[ind]-arr[ind-2]);
     }
     return min(jumpOne,jumpTwo);
}

// Memorization
int funcM(vector<int>&arr,vector<int>&dp,int ind){
    //base 
    if(ind == 0) return 0;
    int jumpTwo = INT_MAX;
    if(dp[ind]!=-1) return dp[ind];
    int jumpOne = funcM(arr,dp,ind-1) + abs(arr[ind]-arr[ind-1]);
    if(ind>1){
        jumpTwo = funcM(arr,dp,ind-2)+ abs(arr[ind]-arr[ind-2]);
    }
    return dp[ind] = min(jumpOne,jumpTwo);

}

// trabular
int frogTab(vector<int>arr){
    int n = arr.size();

    vector<int>dp(n,0);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int jumpOne = dp[i-1] + abs(arr[i]-arr[i-1]);
        int jumpTwo = INT_MAX;
        if(i>1){
            jumpTwo = dp[i-2] + abs(arr[i]-arr[i-2]);
        }
        dp[i] = min(jumpOne,jumpTwo);
    }
    return dp[n-1];
}
// space optimization
int frogSO(vector<int>& arr){
    int prev=0,prev2=0;
    int n = arr.size();
    for(int i=1;i<n;i++){
        int jumpTwo = INT_MAX;
        int jumpOne = prev + abs(arr[i]-arr[i-1]);
        if(i>1){
            jumpTwo = prev2 + abs(arr[i]-arr[i-2]);
        }
        int curr = min(jumpOne,jumpTwo);
        prev2 = prev;
        prev = curr;

    }
    return prev;
}
int main(){
    int n= 4;
    //normal recursion
    vector<int>arr={10,20,30,10};
    cout<<"Recursion Result : " << func(arr,n-1)<<endl;

    vector<int>dp(n+1,-1);
    // funcM(arr,dp,n-1);
    cout<<"Memorization Result: "<< funcM(arr,dp,n-1)<<endl;

    //trabular method 
    cout<<"Tabular method : "<< frogTab(arr)<<endl;

    // space optimization
    cout<<"Space Optimizations : "<< frogSO(arr)<<endl;

}