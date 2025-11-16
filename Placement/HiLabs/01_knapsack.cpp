#include<bits/stdc++.h>
using namespace std;

int solve(int ind,vector<pair<int,int>>&resources,int limit,vector<vector<int>>&dp){
    if(ind == resources.size()) return 0;

    if(dp[ind][limit]!=-1) return dp[ind][limit];
    // nottake 
    int nottake = solve(ind+1,resources,limit,dp);
    // take
    int take =0;
    if(limit <= resources[ind].second){
        take = resources[ind].first + solve(ind+1,resources,limit-resources[ind].second,dp);
    }
    return dp[ind][limit]= max(take,nottake);
}
int maxPeopleRescued(vector<pair<int,int>>resources, int limit){
    
    int n = resources.size();
    vector<vector<int>>dp(n+1,vector<int>(limit+1,-1));
    return solve(0,resources,limit,dp);
}
int main() {
    vector<pair<int,int>> resources = { {3, 2}, {5, 4}, {6, 5} };
    int limit = 7;
    cout << maxPeopleRescued(resources, limit) << endl; // Output: 8 (3+5)
}