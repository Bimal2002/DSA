// #include<bits/stdc++.h>
// using namespace std;

// void dfs(int node,vector<int>adj[],int V,int vis[],vector<int>&dfs_ans){
//        vis[node]=1;
//        dfs_ans.push_back(node);

//        for(auto it : adj[node]){
//           if(!vis[it]){
//             dfs(it,adj,V,vis,dfs_ans);
//           }
//        }

// }
// vector<int>dfsOfGraph(vector<int>adj[],int V){
//     int vis[V]={0};
//     vector<int>dfs_ans;
//     int start =0;

//     dfs(start,adj,V,vis,dfs_ans);
//     return dfs_ans;

// }
// void addEdge(vector<int>adj[],int u,int v){
//     adj[u].push_back(v);
//     adj[v].push_back(u);
// }
// void printAns(vector<int>&ans){
//     for(int i=0;i<ans.size();i++){
//         cout<<ans[i]<<" ";
//     }
// }
// int main(){
//     vector<int>adj[6];
//     addEdge(adj,0,1);
//     addEdge(adj,1,2);
//     addEdge(adj,1,3);
//     addEdge(adj,0,4);
//     vector<int>ans= dfsOfGraph(adj,5);
//     printAns(ans);
// }

// #include<bits/stdc++.h>
// using namespace std;

// bool detect(int src,vector<int>adj[],int vis[]){
//     vis[src]=1;
//     queue<pair<int,int>>q;
//     q.push({src,-1});

//     while(!q.empty()){
//         int node = q.front().first;
//         int parent = q.front().second;
//         q.pop();

//         for(auto adjacentNode : adj[node]){
//             if(!vis[adjacentNode]){
//                 vis[adjacentNode]=1;
//                 q.push({adjacentNode,node});
//             }
//             if(parent != adjacentNode){
//                 return true;
//             }
//         }
//     }
//     return false;
// }
// bool isCycle(int V,vector<int>adj[]){
//     int vis[V]={0};
//     for(int i=0;i<V;i++){
//         if(!vis[i]){
//             if(detect(i,adj,vis))return true;
//         }
//     }
//     return false;
// }

// bool detectUsingDFS(int node,int parent ,vector<int>adj[],int vis[]){
//     vis[node]=1;

//     for(auto adjacentNode : adj[node]){
//         if(!vis[adjacentNode]){
//             if(detectUsingDFS(adjacentNode,node,adj,vis)== true) return true;
//         }
//         else if(adjacentNode != parent) return true;
//     }

//     return false;
// }
// bool isCycleDfs(int V,vector<int>adj[]){
//     int vis[V]={0};
//     for(int i=0;i<V;i++){
//         if(!vis[i]){
//             if(detectUsingDFS(i,-1,adj,vis)==true) return true;
//         }
//     }
//     return false;
// }


// int main() {
    
//     // V = 4, E = 2
//     vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
//     // bool ans1 = isCycle(4,adj);
//     bool ans =isCycleDfs(4, adj);
//     if (ans)
//         cout << "1\n";
//     else
//         cout << "0\n";
//     return 0;
// }


// 



// #include<bits/stdc++.h>
// using namespace std;
// void dfs(int row,int col,vector<vector<char>>&mat,vector<vector<int>>&vis,int delRow[],int delCol[]){
//     vis[row][col]=1;
//     int n = mat.size(),m =mat[0].size();

//     for(int i=0;i<4;i++){
//         int nrow = row + delRow[i];
//         int ncol = col + delCol[i];

//         if(nrow >=0 && nrow <n && ncol >=0 && ncol <m && !vis[nrow][ncol] && mat[nrow][ncol]=='O'){
//             dfs(nrow,ncol,mat,vis,delRow,delCol);
//         }
//     }


// }
// vector<vector<char>>fill(int n,int m,vector<vector<char>>mat){
//     vector<vector<int>>vis(n,vector<int>(m,0));
//     int delRow[]={-1,1,0,0};
//     int delCol[]={0,0,-1,1};
//     for(int i=0;i<n;i++){
//         if(!vis[i][0] && mat[i][0]=='O'){
//             dfs(i,0,mat,vis,delRow,delCol);
//         }
//         if(!vis[i][m-1] && mat[i][m-1]=='O'){
//             dfs(i,m-1,mat,vis,delRow,delCol);
//         }
//     }

//     for(int j=0;j<m;j++){
//         if(!vis[0][j] && mat[0][j]=='O'){
//             dfs(0,j,mat,vis,delRow,delCol);
//         }

//         if(!vis[n-1][j]&& mat[n-1][j]=='O'){
//             dfs(n-1,j,mat,vis,delRow,delCol);
//         }
//     }

//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(!vis[i][j] && mat[i][j]=='O'){
//                 mat[i][j]='X';
//             }
//         }
//     }
//     return mat;
// }
// int main(){
    
//     vector<vector<char>> mat{
//         {'X', 'X', 'X', 'X'}, 
//         {'X', 'O', 'X', 'X'}, 
//         {'X', 'O', 'O', 'X'}, 
//         {'X', 'O', 'X', 'X'}, 
//         {'X', 'X', 'O', 'O'}
//     };
    
//     // n = 5, m = 4
//     vector<vector<char>> ans = fill(5, 4, mat);
//     for(int i = 0;i < 5;i++) {
//         for(int j = 0;j < 4;j++) {
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<"\n";
//     }
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&grid){
    vis[row][col]=1;
    queue<pair<int,int>>q;
    int n = grid.size(),m = grid[0].size();

    q.push({row,col});
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int delRow =-1 ; delRow<=1;delRow++){
            for(int delCol =-1;delCol <=1 ;delCol++){
                int nrow = row+ delRow;
                int ncol = col + delCol;
                if( nrow >=0 && nrow<n && ncol >=0 && ncol <m  && grid[nrow][ncol]=='1' &&  !vis[nrow][ncol]){
                    vis[nrow][ncol]=1; // it is neccesary to add visited 
                    q.push({nrow,ncol});
                }
            }
        }
    }
    
    
}
int numIslands(vector<vector<char>>&grid){
      int n = grid.size();
      int m= grid[0].size();
      vector<vector<int>>vis(n,vector<int>(m,0));

      int cnt =0;
      for(int row =0;row <n; row++){
        for(int col = 0;col<m;col++){
            if(!vis[row][col] && grid[row][col]=='1'){
                cnt++;
                bfs(row,col,vis,grid);
            }
        }
      }

      return cnt;
}
int main() {
    // n: row, m: column
    vector<vector<char>> grid
    {
        {'0', '1', '1', '1', '0', '0', '0'},
        {'0', '0', '1', '1', '0', '1', '0'}
    };

        
    cout << numIslands(grid) << endl;
        
    return 0;
}