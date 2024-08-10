#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    void dfs(int node,vector<int>&vis,vector<int>adj[],vector<int>&dfsResult){
          vis[node]=1;
          dfsResult.push_back(node);
          for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                dfs(it,vis,adj,dfsResult);
            }
          }
    }
};
void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printAns(vector<int>ans ){
   cout<<"Print ";
    for (int  i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
}
int main(){
    vector<int>adj[5];
    addEdge(adj,0,2);
    addEdge(adj,2,4);
    addEdge(adj,0,1);
    addEdge(adj,0,3);
    vector<int>dfsResult;
    vector<int>vis(5,0);
    Graph obj;
    int start=0;
    obj.dfs(start,vis,adj,dfsResult);
    printAns(dfsResult);


}