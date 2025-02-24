#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int>size,parent;
    public:
       DisjointSet(int n){
          size.resize(n+1,0);
          parent.resize(n+1,0);
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

       void unionBySize(int u,int v){
           int ulp_u = findUPar(u);
           int ulp_v = findUPar(v);
           if(ulp_u== ulp_v) return;

           if(size[ulp_u] < size[ulp_v]){
                  parent[ulp_u]=ulp_v; //  attach smaller tree under larger tree
                  size[ulp_v] += size[ulp_u];
           }else{
                  parent[ulp_v] = ulp_u;  // attach smaller tree under the larger tree
                  size[ulp_u] += size[ulp_v]; // increase the size of the larger tree after adding smaller tree to it
                  
           }

       }


};
int main(){
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;

}