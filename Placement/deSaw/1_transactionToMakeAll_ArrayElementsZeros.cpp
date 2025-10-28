#include<bits/stdc++.h>
using namespace std;
// 3 2 1 0
int solve(vector<int>& arr){
    int change =0;
    int n = arr.size();
    for(int i=0;i<n-1;i++){
        change += abs(arr[i]-arr[i+1]);
    }
    if(arr[n-1]!=0){
        change += abs(arr[n-1]);
    }
    return change;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int e;
        cin>>e;
        arr.push_back(e);  
    }
    int ans = solve(arr);
    cout<<ans;

}