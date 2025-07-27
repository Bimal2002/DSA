#include<bits/stdc++.h>
using namespace std;
vector<int>findNSE(vector<int>&arr){
    vector<int>nse(arr.size());
    stack<int>st;
    int n = arr.size();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        nse[i]=st.empty()? n : st.top(); 
        st.push(i);

    }
    return nse;
}
vector<int>findPSEE(vector<int>&arr){
    int n = arr.size();
    vector<int>pse(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] >arr[i]){
            st.pop();
        }
        pse[i]= st.empty()?-1:st.top();
        st.push(i);
    }
    return pse;
}


int sumSubArrayMins(vector<int>&arr){
    int n = arr.size();
    int mod = 1e9+7;
    int total =0;
    vector<int>pse = findPSEE(arr);
    vector<int>nse = findNSE(arr);
    for(int i=0;i<n;i++){
        int left = i- pse[i];
        int right = nse[i]-i;
        total = (total +(left* right*arr[i]) % mod)% mod;
    }
    return total;
}
int main(){
    vector<int>arr={1,4,6,7,3,7,8,1};
    cout<<"Sum of subarrays of minimum : "<<sumSubArrayMins(arr);
    
}