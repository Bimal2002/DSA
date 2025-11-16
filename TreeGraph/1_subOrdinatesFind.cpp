#include<bits/stdc++.h>
using namespace std;
int dfs(int node,vector<vector<int>>&adj,vector<int>&sub){
    sub[node]=1;
    for(int child : adj[node]){
        dfs(child,adj,sub);
        sub[node] += sub[child];
    }
    return sub[node];
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>adj(n+1);
    vector<int>sub(n+1,0);
    for(int i=2;i<=n;i++){
        int boss ;
        cin>>boss;
        adj[boss].push_back(i);
    }
    dfs(1,adj,sub);
    for(int i=1;i<=n;i++){
        cout<<sub[i]-1<<" "; // exclude employee 
    }

}