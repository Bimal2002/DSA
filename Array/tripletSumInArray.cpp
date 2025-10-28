#include<bits/stdc++.h>
using namespace std;
void findTripletSum(vector<int>arr,int target){
    int n = arr.size();
    bool found = false;
    for(int i=0;i<n-2;i++){
        unordered_set<int>seen;
        for(int j=i+1;j<n;j++){
            int third = target - arr[i] - arr[j];
            if(seen.find(third)!=seen.end()){
                //  cout<<"found";
                 found = true;
                 break;

            }  
            seen.insert(arr[j]);

        }
    }
    if(!found){
        cout<<"Not found";
    }else{
        cout<<"Found";
    }

}

bool tripletSumFound(vector<int>arr, int target){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-2;i++){
        int reqSum = target - arr[i];
        int l = 0, r = n-1;
        while(l<r){
            if(reqSum == arr[l]+arr[r]){
               return true;
            }
            else if(reqSum > arr[l] + arr[r]){
                r--;
            }else{
                l++;
            }

        }
    }
    return false;
}
int main(){
    vector<int>arr={10,20,30,40};
    int sum =60;
    findTripletSum(arr,sum);

    if(tripletSumFound(arr,sum)){
        cout<<"found";
    }else{
        cout<<"Not found";
    }

}