#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElementsCircular(vector<int>& nums) {
    int n = nums.size();
    vector<int> nge(n, -1);
    stack<int> st; // stores indices

    for (int i = 2 * n - 1; i >= 0; i--) {
        int idx = i % n;
        while (!st.empty() && nums[st.top()] <= nums[idx]) {
            st.pop();
        }
        if (i < n && !st.empty()) {
            nge[idx] = nums[st.top()];
        }
        st.push(idx);
    }

    return nge;
}

vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> nge(n, -1);
    stack<int> st; // stores indices

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] <= nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            nge[i] = nums[st.top()];
        }
        st.push(i);
    }
    return nge;
}

int main(){
    vector<int>nums={1,2,5,4,3};
    vector<int>ans = nextGreaterElement(nums);
    for(int it : ans){
        cout<<it <<" ";
    }
}
