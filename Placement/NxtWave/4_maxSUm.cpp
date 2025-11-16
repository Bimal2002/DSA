#include <bits/stdc++.h>
using namespace std;
unordered_map<int, long long> freq;
vector<int> dp;
long long solve(int i)
{
    if (i <= 0)
        return 0;
    if (i == 1)
        return freq.count(1) ? freq[1] : 0;
    if (dp[i] != -1)
        return dp[i];

    long long take = (freq.count(i) ? freq[i] : 0) + solve(i - 2);
    long long skip = solve(i - 1);
    return dp[i] = max(take, skip);
}
long long maxSum(vector<int> &arr)
{
    int mx = 0;
    // build points map : val to sum of that value
    for (int x : arr)
    {
        freq[x] += x;
        mx = max(mx, x);
    }
    dp.assign(mx + 1, -1);
    return solve(mx);
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long ans = maxSum(arr);
    cout << ans;
}