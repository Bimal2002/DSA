#include <bits/stdc++.h>
using namespace std;
bool canAdd(int num, vector<int> &current)
{
    for (int x : current)
    {
        if (x % num != 0 && num % x != 0)
        {
            return false;
        }
    }
    return true;
}
void solve(int ind, vector<int> &nums, vector<int> &current, vector<int> &result)
{
    // base case
    if (ind == nums.size())
    {
        if (current.size() > result.size())
        {
            result = current;
        }
        return;
    }

    // nottake
    solve(ind + 1, nums, current, result);
    // take

    if (current.size() == 0 || canAdd(nums[ind], current))
    {
        current.push_back(nums[ind]);
        solve(ind + 1, nums, current, result);
        current.pop_back();
    }
}
int longestDivisibleSubset(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<int> current, result;
    solve(0, nums, current, result);
    return result.size();
}
int main()
{
    vector<int> nums = {1, 2, 4, 18, 6};
    int ans = longestDivisibleSubset(nums);
    cout << ans;
}