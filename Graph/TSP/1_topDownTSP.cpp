/*
 Given n cities and a cost matrix cost[i][j], find the minimum cost to:
 0 → visit all nodes → 0


*/
#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n;
vector<vector<int>>cost;
vector<vector<int>>dp;
int tsp(int mask,int pos){
    //base case all cities visited ,return cost to go back to start
    if(mask == (1<<n)-1){
        return cost[pos][0];
    }
    // if already computed, return stored result
    if(dp[mask][pos]!=-1){
        return dp[mask][pos];
    }
    int ans = INF;

    // trying visiting each city that hasn't been visited yet

    for(int next = 0 ; next <n ; next++){
        if(mask & (1<< next)) continue; // already visited
        int newMask =mask | (1<<next);
        int newCost = cost[pos][next] + tsp(newMask,next);
        ans =  min(ans,newCost);
    }
    return dp[mask][pos] = ans;
}
int main(){
    cin>>n;
    cost.assign(n,vector<int>(n));

    //read cost matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>cost[i][j];
        }
    }
    dp.assign(1<<n,vector<int>(n,-1));
    //start from city 0 with only it visited (mask =1)
    int result = tsp(1<<0,0);
    cout<<"Minimum Cost: "<<result<<endl;
}