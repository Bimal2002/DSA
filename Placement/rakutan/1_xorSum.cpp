#include<bits/stdc++.h>
using namespace std;
vector<int>solve(vector<int>&type,vector<int>&oper){
    vector<int>ans;
    // vector<int>arr;
    unordered_map<int,int>mp;
    int n = type.size();
    for(int i=0;i<n;i++){
        if(type[i]==1){
           mp[oper[i]]++;
        }else if(type[i]==2){
            if(mp.find(oper[i])!= mp.end()){
                mp.erase(oper[i]);
            }
        }else if(type[i]==3){
            if(mp.empty()){
                ans.push_back(0);
            }else{
                
                long long currSum = 0;
               for(auto it: mp){
                   int el = it.first;
                   int cnt = it.second;
                   currSum += (long long)cnt*(el ^ oper[i]);
                   
               }
               ans.push_back((int)currSum);
            } 
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>type(n);
        vector<int>oper(n);
        for(int i=0;i<n;i++){
            cin>>type[i];
        }
        for(int i=0;i<n;i++){
            cin>>oper[i];
        }
        vector<int>ans = solve(type,oper);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}