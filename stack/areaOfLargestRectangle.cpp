#include <bits/stdc++.h>
using namespace std;
vector<int>PSE(vector<int>&arr){
    stack<int>st;
    vector<int>pse(arr.size());
    for(int i=0;i<arr.size();i++){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        pse[i]=st.empty()?-1: st.top();
        st.push(i);
    }
    return pse;
}
vector<int>NSE(vector<int>&arr){
    stack<int>st;
    vector<int>nse(arr.size());
    for(int i= arr.size();i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
            
        }
        nse[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return nse;
}
int largestRectangleArea(vector<int>&heights){
    int maxArea =INT_MIN;
    vector<int>nse = NSE(heights);
    vector<int>pse = PSE(heights);
    for(int i=0;i<heights.size();i++){
        int height = heights[i];
        int width = nse[i]-pse[i]-1;
        int area = height*width;
        maxArea = max(maxArea,area);
    }
    return maxArea;
}
int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3, 1};

    cout << "The largest area in the histogram is " << largestRectangleArea(heights);
    return 0;
}
