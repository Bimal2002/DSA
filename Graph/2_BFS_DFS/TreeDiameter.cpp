#include<bits/stdc++.h>
using namespace std;
pair<int,int>findFarthestNode(int n,unordered_map<int,vector<int>>&adj,int sourceNode){
    queue<int>q;
    vector<bool>vis(n,false);
    // push source node into the queue
    q.push(sourceNode);
    vis[sourceNode]=true;
    int maximumDist = 0;
    int farthestNode = sourceNode;

    // explore neighbors
    while(!q.empty()){
        int size = q.size();
        while (size--)
        {
            int currNode = q.front();
            q.pop();
            farthestNode = currNode;
            for(int nei : adj[currNode]){
                if(!vis[nei]){
                    vis[nei]= true;
                    q.push(nei);
                }
            }
            
        }
        if(!q.empty()) maximumDist++;
    }
    return {farthestNode,maximumDist};
}
int findDiameter(int n,unordered_map<int,vector<int>>&adj){

    // first bfs to find the farthest node from any arbitary node (e.g. 0)
    auto [farthestNode,_] = findFarthestNode(n,adj,0);
    

    // source bfs from the farthest node to determine the diameter
    auto [_,diameter] = findFarthestNode(n,adj,farthestNode);
    return diameter;
}
int treeDiameter(vector<vector<int>>&edges){
    // no of nodes in the tree
    int n = edges.size()+1;
    // build adjList
    unordered_map<int,vector<int>>adj;
    for(auto &it : edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    // Find the diameter of the tree
    return findDiameter(n,adj);
}
int main(){

}