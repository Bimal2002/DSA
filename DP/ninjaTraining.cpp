#include<bits/stdc++.h>
using namespace std;
int func(int day,int last,vector<vector<int>>&points,vector<vector<int>>&dp){
    // if previously result got
    if(dp[day][last]!=-1) return dp[day][last];
    //on 0th day pick the activity which is giving best result , on 0th day there is no restriction of last day check
    if(day==0){
        int maxi=0;
        for(int i=0;i<=2;i++){
            if(i!=last){
                maxi = max(maxi,points[0][i]);
            }
        }
        return dp[day][last] = maxi;
    }

    int maxi=0;
    for(int i=0;i<=2;i++){
        if(i!= last){
            int activity = points[day][i] + func(day-1,i,points,dp);
             maxi = max(maxi,activity);
        }

    }
    return dp[day][last] = maxi;
}
int ninjaTraining(int n,vector<vector<int>>& points){
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return func(n-1,3,points,dp);
}
int main() {
  // Define the points matrix
  vector<vector<int>> points = {{10, 40, 70},
                                 {20, 50, 80},
                                 {30, 60, 90}};

  int n = points.size();  // Get the number of days
  // Call the ninjaTraining function to find the maximum points and print the result
  cout << ninjaTraining(n, points);
}

