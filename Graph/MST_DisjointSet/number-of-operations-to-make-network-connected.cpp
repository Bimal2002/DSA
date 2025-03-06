#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int>parent,rank,size;
    public:
       DisjointSet(int n){
         parent.resize(n+1,0);
         rank.resize(n+1,0);
         size.resize(n+1,1);
         for(int i=0;i<=n;i++){
            parent[i]=i;
         }
       }
       int findUPar(int node){
           if(node == parent[node]){
              return node;
           }
           return parent[node] = findUPar(parent[node]);        
       }
       void unionByRank(int u,int v){
           int ulp_u = findUPar(u);
           int ulp_v = findUPar(v);
           if(ulp_u == ulp_v) return ;
           if(rank[ulp_u]<rank[ulp_v]){
              parent[ulp_u]= ulp_v;
           }else if(rank[ulp_u] > rank[ulp_v]){
              parent[ulp_v] = ulp_u;
           }else{   // if rank[ulp_u]== rank[ulp_v]
              rank[ulp_u]++;
           }
       }
       void unionBySize(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v ) return;
        if(size[ulp_u] < size[ulp_v]){
           parent[ulp_u]= ulp_v;
           size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v]= ulp_u;
            size[ulp_u] += size[ulp_v];
        }
       }

};
int Solve(int V,vector<vector<int>>&edge){
       DisjointSet ds(V);
       int extraEdges=0;
       // Step 1: count extra edges 
       for(auto it : edge){
           int u = it[0],v=it[1];
           if(ds.findUPar(u) == ds.findUPar(v)){
              extraEdges++;
           }else{
              ds.unionBySize(u,v);
           }
       }
       // step 2: Count Components
       int components =0;
       for(int i=0;i<V;i++){
        if(ds.findUPar(i)==i){
            components++;
        }
       }
       int neededEdges = components-1; //because we need (componenets-1) edges to connect all the edges
       return (extraEdges >= neededEdges) ? neededEdges:-1;

       
}

int main(){
   

    int V = 9;
    vector<vector<int>> edge = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {2, 3}, {4, 5}, {5, 6}, {7, 8}};

    int ans = Solve(V, edge);
    cout << "The number of operations needed: " << ans << endl;
    return 0;

}