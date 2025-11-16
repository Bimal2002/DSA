#include<bits/stdc++.h>
using namespace std;
int findMinimumOperations(vector<long long>&arr,int k){
    long long maxi = *max_element(arr.begin(),arr.end());

    int ops = 0;
    while(maxi<k){
        maxi = maxi*2;
        ops++;
    }
    return ops;
}
int main(){
    int n ,k;
    cin>>n>>k;
    vector<long long>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ans  = findMinimumOperations(arr,k);
    cout<<ans;

}