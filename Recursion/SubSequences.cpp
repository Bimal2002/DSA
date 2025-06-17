#include <bits/stdc++.h>
using namespace std;
void generateSubsequences(string &s, int i, string current, vector<string> &result)
{

    if (i == s.length())
    {
        result.push_back(current);
        return;
    }
    // include s[i]
    generateSubsequences(s, i + 1, current + s[i], result);
    // exclude s[i]
    generateSubsequences(s, i + 1, current, result);
}

// Generate All Subsets of an Array
void generateSubsets(vector<int> &arr, int i, vector<int> &current, vector<vector<int>> &result)
{
    if (i == arr.size())
    {
        result.push_back(current);
        return;
    }

    // include arr[i]
    current.push_back(arr[i]);
    generateSubsets(arr, i + 1, current, result);

    // backtrack & exclude arr[i]
    current.pop_back();
    generateSubsets(arr, i + 1, current, result);
}

// Subsequences of String with Duplicate Characters
void uniqueSubsequences(string &s, int i, string current, set<string> &result)
{
    // base case
    if (i == s.size())
    {
        result.insert(current);
        return;
    }
    // pick
    uniqueSubsequences(s, i + 1, current + s[i], result);
    // not pick
    uniqueSubsequences(s, i + 1, current, result);
}

//  Subsequences of Length Exactly k
void kLengthSubsequences(string s, int i, string current, int k)
{
    if (i == s.length())
    {
        if (current.length() == k)
        {
            cout << current << " ";
        }
        return;
    }

    // pick
    kLengthSubsequences(s, i + 1, current + s[i], k);

    // not pick
    kLengthSubsequences(s, i + 1, current, k);
}

// Filter Subsequences by a Condition (e.g., sum = k)
void subsequenceWithSum(vector<int> &arr, int i, vector<int> &current, int sum, int target)
{
    // base case
    if (i == arr.size())
    {
        if (sum == target)
        {
            for (int x : current)
            {
                cout << x << " ";
            }
            cout << endl;
        }
        return;
    }

    // pick
    current.push_back(arr[i]);
    subsequenceWithSum(arr, i + 1, current, sum + arr[i], target);

    // backtrack
    current.pop_back();
    subsequenceWithSum(arr, i + 1, current, sum, target);
}

// Count All Subsequences With Sum = K
int countSubsequences(vector<int> &arr, int i, int sum, int target)
{
    // base
    if (i == arr.size())
    {
        return (sum == target) ? 1 : 0;
    }
    // pick
    int left = countSubsequences(arr, i + 1, sum + arr[i], target);

    // not pick
    int right = countSubsequences(arr, i + 1, sum, target);

    return left + right;
}

// Print Only One Valid Subsequence With Sum = K
bool printOneSubsequence(vector<int> &arr, int i, vector<int> &current, int sum, int k)
{
    if (i == arr.size())
    {
        if (sum == k)
        {
            for (int x : current)
                cout << x << " ";
            return true;
        }
        return false;
    }

    // pick
    current.push_back(arr[i]);
    if (printOneSubsequence(arr, i + 1, current, sum + arr[i], k))
        return true;

    // not pick
    current.pop_back();
    if (printOneSubsequence(arr, i + 1, current, sum, k))
        return true;

    return false;
}

/* Print Only One Valid Subsequence With Sum = K */
void findSubSet(int ind, vector<int> arr, int k, int sum, vector<int> subset)
{
    // base case
    if (ind == arr.size())
    {
        if (sum == k)
        {  
            cout<<'[';
            for (int i = 0; i < subset.size(); i++)
            {
                cout << subset[i] ;
                if(i!= subset.size()-1) cout<<',';
            }
            cout<<']'<<endl;

            
        }
        
        return;
    }
    // pick
    subset.push_back(arr[ind]);
    findSubSet(ind + 1, arr, k, sum + arr[ind], subset);

    // not pick
    subset.pop_back();
    findSubSet(ind + 1, arr, k, sum, subset);
}

 // count subsets 
int countSubsets(int index, vector<int>& arr, int sum, int k) {
    if (index == arr.size()) {
        return sum == k ? 1 : 0;
    }

    // Include current element
    int include = countSubsets(index + 1, arr, sum + arr[index], k);

    // Exclude current element
    int exclude = countSubsets(index + 1, arr, sum, k);

    return include + exclude;
}

int main()
{
    // string s = "abc";
    // vector<string> result;
    // generateSubsequences(s, 0, "", result);
    // for (string str : result)
    // {
    //     cout << str << endl;
    // }

    /* Generate All Subsets of an Array */

    // vector<int> arr = {1, 2};
    // vector<vector<int>> result1;
    // vector<int> current;
    // generateSubsets(arr, 0, current,result1);

    // for (auto subset : result1)
    // {
    //     for (int num : subset)
    //     {
    //         cout << num ;
    //     }
    //     cout << endl;
    // }

    /* Subsequences of String with Duplicate Characters */

    // string s = "aab";
    // set<string>result2;
    // uniqueSubsequences(s,0,"",result2);
    // for(auto & str : result2){
    //     cout<<str<<" ";
    // }

    /* Subsequences of Length Exactly k */

    // string s ="abc";
    // int k =2 ;
    // kLengthSubsequences(s,0,"",k);

    /* Filter Subsequences by a Condition (e.g., sum = k) */

    // vector<int> arr = {1, 2, 1};
    int target = 2;
    vector<int> current;

    // subsequenceWithSum(arr,0,current,0, target);

    /* Count All Subsequences With Sum = K */
    // int ans = countSubsequences(arr, 0, 0, target);
    // cout << ans;

    /* Print Only One Valid Subsequence With Sum = K */
    vector<int> arr = {1, 2, 1};
    int k = 2;
    vector<int> subset;
    findSubSet(0, arr, k, 0, subset);



    /*  Count subsets */
    cout<<countSubsets(0,arr,0,k);
}