#include<bits/stdc++.h>
using namespace std;

bool isPrime(int x){
    if(x<2) return false;
    for(int i=2;i*i<=x;i++){
        if(x%2 == 0) return false;
    }
    return true;
}


vector<int>findMinimumStpes(int n,vector<int>&arr){
   // map : value -> all positions having thay value
   unordered_map<int,vector<int>>mp;
   int maxVal = 0;
   for(int i=0;i<n;i++){
      mp[arr[i]].push_back(i);
      maxVal = max(maxVal,arr[i]);
   }
   vector<int>dist(n,-1);
   queue<int>q;

   dist[0]=0;
   q.push(0);

   unordered_set<int>usedPrimeValues;
   while(!q.empty()){
    int i= q.front();
    q.pop();
    // step 
    int d = dist[i];
    // move to i-1
     if(i-1>=0 && dist[i-1]==-1){
        dist[i-1]=d+1;
        q.push(i-1);
     }
     // move to i+1
     if(i+1 <n && dist[i+1]==-1){
        dist[i+1]=d+1;
        q.push(i+1);
     }
     if(isPrime(arr[i]) && !usedPrimeValues.count(arr[i])){
        usedPrimeValues.insert(arr[i]);
        int primeVal = arr[i];
        // jump to multiples of primeVal
        for(int mul = primeVal;mul<= maxVal;mul += primeVal){
            if(mp.count(mul)){
                for(int j : mp[mul]){
                    if(dist[j]==-1){
                        dist[j]=d+1;
                        q.push(j);
                    }
                }
            }
        }
     }
   }
   return dist;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>ans = findMinimumStpes(n,arr);
    for(int num : ans){
        cout<<num<<" ";
    }
}