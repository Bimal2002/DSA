#include<bits/stdc++.h>
using namespace std;
vector<int>bfsTrav(int V,vector<int>adjList[]){
    int vis[V]={0};
    vis[0]=1;
    queue<int>q;
    q.push(0);
    vector<int>bfs;
    while (!q.empty())
    {
        int node = q.front();
        cout<<"Print the node "<<node<<" ";
        q.pop();
        bfs.push_back(node);
        for(auto it : adjList[node]){
            if (!vis[it])
            {
                vis[it]=1;
                q.push(it);
            }
            
        }
    }
    return bfs;
    
}
int main(){
    int n;
    int m;  
    cout<<"enter the number of node of the graph : " ;
    cin>>n;
    cout<<"enter the edage : ";
    cin>>m;
    // 
    //vector<vector<int,int>>adjMatrix( n,vector<int>(m,0));
    int adjMatrix[n+1][n+1];
    vector<int>adjList[n+1];
    for (int i = 0; i < m; i++)
    {   
        int u,v;
        cin>>u>>v;
        adjMatrix[u][v]=1;
        adjMatrix[v][u]=1;
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        
    }
    
}