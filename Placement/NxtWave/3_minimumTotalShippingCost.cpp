#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>its  ;
int  boxC ,n;
vector<int>dp;
int solve(int i){
    if(i==n) return 0;

     if(dp[i]!=-1) return dp[i];
    int minCost = INT_MAX;
    int currLength = 0;
    int maxSecurity = 0;
    // try to pack items i... j in the same box
    for(int j=i;j<n;j++){
        currLength  += its[j][0];
        if(currLength >boxC) break;

        maxSecurity = max(maxSecurity,its[j][1]);
        int cost = maxSecurity + solve(j+1);
        minCost = min(minCost,cost);
    }
    return  dp[i]= minCost;

}
int minTotalShippingCost(vector<vector<int>>&items,int boxCapacity){
     its = items;
     boxC = boxCapacity;
     n  = items.size();
     dp.assign(n,-1);
     return solve(0);
     
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>items(n,vector<int>(2));
    for(int i=0;i<n;i++){
        int u ,v;
        cin>>u>>v;
        items.push_back({u,v});
    }
    int boxCapacity;
    cin>>boxCapacity;
    int ans = minTotalShippingCost(items,boxCapacity);
}