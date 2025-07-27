#include<bits/stdc++.h>
using namespace std;
vector<int>findPSEE(vector<int>&arr){
   int n  = arr.size();
   stack<int>st;
   vector<int>pse(n);
   for(int i=0;i<n;i++){
    while(!st.empty() && arr[st.top()] > arr[i]){
        st.pop();
    }
    pse[i] =(st.empty())?-1 : st.top();
    st.push(i);
   }
   return pse;
}
vector<int>findNSE(vector<int>&arr){
   int n = arr.size();
   stack<int>st;
   vector<int>nse(n);
   for(int i=n-1;i>=0;i--){
    while(!st.empty() && arr[st.top()] >= arr[i]){
        st.pop();
    }
    nse[i] = st.empty() ? n: st.top();
    st.push(i);
   }
   return nse;
}
vector<int>findPGE(vector<int>& arr){
    int n = arr.size();
    stack<int>st;
    vector<int>pge(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] < arr[i]){
            st.pop();
        }
        pge[i]=st.empty()? -1 : st.top();
        st.push(i);
    }
    return pge;

}
vector<int>findNGE(vector<int>&arr){
    int n = arr.size();
    stack<int>st;
    vector<int>nge(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]<= arr[i]){
            st.pop();
        }
        nge[i]=st.empty() ? n : st.top();
        st.push(i);
    }
    return nge;

}
int sumOfSubarrayRanges(vector<int>& arr){
    int n  =arr.size();
    int mod = 1e9+7;
    int total =0;
    vector<int>pse = findPSEE(arr);
    vector<int>nse = findNSE(arr);
    vector<int>pge = findPGE(arr);
    vector<int>nge = findNGE(arr);
    int TotalMin =0, TotalMax =0;
    for(int i=0;i<n;i++){
        int leftMin = i - pse[i];
        int rightMin = nse[i]-i;
        TotalMin = (TotalMin+ (leftMin* rightMin*arr[i])%mod)%mod;

        int leftMax = i - pge[i];
        int rightMax = nge[i]-i;
        TotalMax =(TotalMax+ (leftMax*rightMax* arr[i])%mod)%mod;

    }
    int ans = (TotalMax-TotalMin)%mod;
    return ans;


}
int main() {
    vector<int> arr = {1, 4, 6, 7, 3, 7, 8, 1};
    cout << "Sum of subarray ranges: " << sumOfSubarrayRanges(arr) << endl;
    return 0;
}