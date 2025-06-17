#include <bits/stdc++.h>
using namespace std;
void findCombination(int index, vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> ds)
{
    // base case
    if (index == arr.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }

    // pick
    if (arr[index] <= target)
    {
        ds.push_back(arr[index]);
        findCombination(index, arr, target - arr[index], ans, ds);
        ds.pop_back();
    }
    // not pick
    findCombination(index + 1, arr, target, ans, ds);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, candidates, target, ans, ds);
    return ans;
}

// find combination 2
void findCombination2(int ind, vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> ds)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = ind; i < arr.size(); i++)
    {
        if (i > ind && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > target)
            break;
        ds.push_back(arr[i]);
        findCombination2(i + 1, arr, target - arr[i], ans, ds);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination2(0, candidates, target, ans, ds);
    return ans;
}

/*  Combination Sum 3 : */
void solve(int start,vector<vector<int>>&ans,int k,vector<int>res,int n){
    if(res.size()==k && n==0 ){
        ans.push_back(res);
        return ;
    }
    if(n<0 || res.size()>k){
        return ;

    }

    for(int i=start ;i<=9;i++){
        res.push_back(i);
        solve(i+1,ans,k,res,n-i);
        res.pop_back();

    }
}
vector<vector<int>> combinationSum3(int k, int n){
     vector<int>res;
     vector<vector<int>>ans;
     solve(1,ans,k,res,n);
     return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int target = 7;
    vector<vector<int>> ans = combinationSum(arr, target);

    cout << "Combinations are: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    /* Combination Sum 2 :  Problem Statement: Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target. Each number in candidates may only be used once in the combination.

    Note: The solution set must not contain duplicate combinations.

    Examples:

    Example 1:

    Input: candidates = [10,1,2,7,6,1,5], target = 8

    Output:
    [
    [1,1,6],
    [1,2,5],
    [1,7],
    [2,6]]*/
    vector<int> v{10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> comb = combinationSum2(v, 8);

    cout << "[ ";
    for (int i = 0; i < comb.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < comb[i].size(); j++)
        {
            cout << comb[i][j] << " ";
        }
        cout << "]";
    }
    cout << " ]";

    /*    Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

  Only numbers 1 through 9 are used.
  Each number is used at most once.
  Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order. */

    int n = 9, k = 3;
    vector<vector<int>>ans1 = combinationSum3(k, n);
    cout<<'\n'<<"Combination Sum 3"<<endl;
    cout << "[ ";
    for (int i = 0; i < ans1.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < ans1[i].size(); j++)
        {
            cout << ans1[i][j] << " ";
        }
        cout << "]";
    }
    cout << " ]";


}