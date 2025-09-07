#include<bits/stdc++.h>
using namespace std;
int merge(vector<int>&arr,int low,int mid,int high){
    int left = low, right = mid+1;
    int cnt =0;
    vector<int>temp;
    while(left <= mid && right <= high){
        if(arr[left]<=arr[right]){
           temp.push_back(arr[left]);
           left++;
        }else{
            temp.push_back(arr[right]);
            cnt +=(mid-left+1);
            right++;
        }
    }

    while(left<= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    return cnt;
}
int mergeSort(vector<int>&arr,int low,int high){
    if(low>= high) return 0;
    int cnt =0;
    int mid = low + (high-low)/2;
    cnt += mergeSort(arr,low,mid);
    cnt += mergeSort(arr,mid+1,high);
    cnt += merge(arr,low,mid,high);
    return cnt;
}
int inversionCount(vector<int>&arr,int n){
     return mergeSort(arr,0,n-1);
     
}
int main(){
    vector<int>arr ={5,4,3,2,1};
    int n = arr.size();
    int ans = inversionCount(arr,n);
    cout<<ans;
}