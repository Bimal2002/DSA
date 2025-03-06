#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int low,int mid,int high){
    vector<int>temp;
    int left = low;
    int right = mid+1;
    while(left<=mid && right <= high){
         if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
         }else{
            temp.push_back(arr[right]);
            right++;
         }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low;i<=high;i++){
        arr[i] = temp[i-low];
    }

    
}
void MergeSort(int arr[],int low,int high){
    if(low >= high){
        return;
    }
    
    int mid = (low+high)/2;
    MergeSort(arr,low,mid);
    MergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main(){

    int arr[]={4,3,2,1,6,8,0};
    MergeSort(arr,0,6);
    int n= 7;
    for(int i=0;i<n;i++){
       cout<<arr[i]<<" ";
    }

}