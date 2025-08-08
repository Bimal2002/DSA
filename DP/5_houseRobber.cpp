#include <bits/stdc++.h>
using namespace std;
int funcUtils(int ind, vector<int> arr, vector<int> &dp)
{

    if (ind == 0)
        return arr[ind];
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];

    int take = arr[ind] + funcUtils(ind - 2, arr, dp);
    int nottake = 0 + funcUtils(ind - 1, arr, dp);
    return dp[ind] = max(take, nottake);
}
// Memo
int solve(int n, vector<int> &arr)
{
    vector<int> dp(n, -1);
    return funcUtils(n - 1, arr, dp);
}
// Tab
int solveTab(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 0);
    dp[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        int take = arr[i];
        if (i > 1)
            take += dp[i - 2];
        int nottake = 0 + dp[i - 1];
        dp[i] = max(take, nottake);
    }
    return dp[n - 1];
}
int solSO(vector<int> &arr)
{
    int n = arr.size();
    int prev = arr[0];
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int take = arr[i];
        if (i > 1)
            take += prev2;
        int nottake = 0 + prev;
        int curr_i = max(take, nottake);
        prev2 = prev;
        prev = curr_i;
    }
    return prev;
}
int robberStreet(vector<int> arr)
{
    int n = arr.size();
    if (n == 1)
        return arr[0];
    vector<int> arr1, arr2;
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            arr1.push_back(arr[i]);
        if (i != 0)
            arr2.push_back(arr[i]);
    }
    int ans1 = solSO(arr1);
    int ans2 = solSO(arr2);
    return max(ans1, ans2);
}
int main()
{
    vector<int> arr = {2, 1, 4, 9};
    int n = arr.size();
    cout << "Memo Result: " << solve(n, arr) << endl;

    cout << "Tab Result : " << solveTab(arr) << endl;

    cout << "Space Opt : " << solSO(arr) << endl;

    cout << "House Robber in circular : " << robberStreet(arr) << endl;
}