#include <bits/stdc++.h>
using namespace std;
vector<int> findPSE(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pse(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pse;
}
vector<int> findNSE(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nse(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nse;
}
int lHist(vector<int> heights)
{
    int n = heights.size();
    vector<int> pse = findPSE(heights);
    vector<int> nse = findNSE(heights);
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        int width = (nse[i] - pse[i] - 1);
        int height = heights[i];
        maxArea = max(maxArea, width * height);
    }
    return maxArea;
}
int maxRec(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> prefixSum(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 1)
            {
                prefixSum[i][j] = (i == 0) ? 1 : (prefixSum[i - 1][j] + 1);
            }
            else
            {
                prefixSum[i][j] = 0;
            }
        }
    }
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        maxArea = max(maxArea, lHist(prefixSum[i]));
    }
    return maxArea;
}
int main()
{
    vector<vector<int>> matrix = {
        {1, 0, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}};
    cout << "Max Rectangle Area : " << maxRec(matrix);
}