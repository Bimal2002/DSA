#include<bits/stdc++.h>
using namespace std;
vector<int>modules;
vector<vector<int>>dp;
int n;
// int solve(int  i,int  nextInd){
//       if(i == n) return 0;
//       //prev return 
//       if(dp[i][nextInd]!=-1) return dp[i][nextInd];

//       // option 1: not take
//       int nottake  = solve(i+1,nextInd);
//       int take =0;
//       if(nextInd == modules[i]){
//          take = 1 + solve(i+1,nextInd+1);
//       }

//       return dp[i][nextInd] = max(take,nottake);

// }
int solve(int i, int prev) {
    if(i == n) return 0;
    if(dp[i][prev+1] != -1) return dp[i][prev+1];

    int notTake = solve(i+1, prev);
    int take = 0;
    if(prev == -1 || modules[i] > modules[prev]) {
        take = 1 + solve(i+1, i);
    }
    return dp[i][prev+1] = max(take, notTake);
}

int main(){
    cin>>n;
    modules.resize(n);
    for(int i=0;i<n;i++){
        cin>>modules[i];
    }
    dp.assign(n+1,vector<int>(n+5,-1));
    // int ans = solve(0,1); // start at 0th index , and it is 1-base indexing so nextIndex is 1
    int ans = solve(0,-1);
    cout<<ans;
    
}