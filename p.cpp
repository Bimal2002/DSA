/* #############                 bfs

#include<bits/stdc++.h>
using namespace std;
vector<int>bfsOfGraph(vector<int>adj[],int V){
    int vis[V]={0};
    vis[0]=1;
    queue<int>q;
    q.push(0);
    vector<int>bfs;
    while (!q.empty())
    {
        int node=q.front();
        bfs.push_back(node);
        q.pop();
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
}
void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printAns(vector<int>&ans){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    vector<int>adj[6];
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,0,4);
    vector<int>ans= bfsOfGraph(adj,5);
    printAns(ans);


}*/

/*                                     dfs


#include<bits/stdc++.h>
using namespace std;
void dfs(int vis[],vector<int>adj[],int node,vector<int>&ls){
     vis[node]=1;
     ls.push_back(node);
     for (auto it: adj[node])
     {
        if(!vis[it]){
            dfs(vis,adj,it,ls);
        }
     }


}
vector<int>dfsOfGraph(vector<int>adj[],int V){
    int start=0;
    int vis[V]={0};
    vector<int>ls;
    dfs(vis,adj,start,ls);
    return ls;
}
void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printAns(vector<int>&ans){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    vector<int>adj[6];
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,0,4);
    vector<int>ans= dfsOfGraph(adj,5);
    printAns(ans);
}

 */

/*                                    Number of Provinces                                     

#include <bits/stdc++.h>
using namespace std;

void dfs(int vis[],int node,vector<int>adjLs[]){
    vis[node]=1;
    for(auto it: adjLs[node]){
         if(!vis[it]){
            dfs(vis,it,adjLs);
         }
    }

}

int numberOfProvinces(vector<vector<int>> &adj, int V)
{
    int n = adj.size();
    vector<int> adjLs[n + 1];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (adj[i][j] == 1 && i != j)
            {
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }
    int vis[V]={0};
    int cnt=0;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            cnt++;
            dfs(vis,i,adjLs);
        }
    }
    return cnt;
}

int main()
{
    vector<vector<int>> adj{
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}};
    int ans = numberOfProvinces(adj, 3);
    cout<<ans<<" ";
}
*/


/*                                   Number of Islands                               



#include<bits/stdc++.h>
using namespace std;
void bfs(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&vis){
    vis[row][col]=1;
    int n = grid.size();
    int m= grid[0].size();
    queue<pair<int,int>>q;
    q.push({row,col});
    while (!q.empty())
    {
        int row= q.front().first;
        int col= q.front().second;
        q.pop();
        for ( int delrow=-1;delrow<=1;delrow++)
        {
            for(int delcol=-1;delcol<=1;delcol++){
                int nrow = row+ delrow;
                int ncol= col+ delcol;
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        
    }
    
}
int numberIslands(vector<vector<char>>&grid){
       int n= grid.size();
       int m=grid[0].size();
       vector<vector<int>>vis(n,vector<int>(m,0));
       int cnt=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j]=='1'){
                cnt++;
                bfs(i,j,grid,vis);
            }
        }
       }
       return cnt;
}

int main(){
    vector<vector<char>> grid
    {
        {'0', '1', '1', '1', '0', '0', '0'},
        {'0', '0', '1', '1', '0', '1', '0'}
    };
    int ans = numberIslands(grid);
    cout<<ans;
}
*/


/*                                   flood-fill algorithm                                  
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>&image,vector<vector<int>>&ans,int delrow[],int delcol[],int inColor,int newColor,int row,int col){
    ans[row][col]=newColor;
    int n= image.size();
    int m=image[0].size();
    for(int i=0;i<4;i++){
        int nrow= row + delrow[i];
        int ncol= col + delcol[i];
        if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && image[nrow][ncol]== inColor && ans[nrow][ncol]!= newColor){
            dfs(image,ans,delrow,delcol,inColor,newColor,nrow,ncol);
        }

    }

}
vector<vector<int>>floodfill(vector<vector<int>>&image,int sr,int sc,int newColor){
    vector<vector<int>>ans= image;
    int delrow[]={-1,0,1,0};
    int delcol[]={0,-1,0,1};
    int inColor= image[sr][sc];
    dfs(image,ans,delrow,delcol,inColor,newColor,sr,sc);
    return ans;
}
int main(){
    vector<vector<int>>image{
	    {1,1,1},
	    {1,1,0},
	    {1,0,1}
	};
	
    // sr = 1, sc = 1, newColor = 2  
    vector<vector<int>>ans=floodfill(image,1,1,2);
    for (int i = 0; i < 3; i++)
    {
        for(int j=0;j<3;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    

}
 */


/*                                    Cycle detection                                    

#include<bits/stdc++.h>
using namespace std;
bool detect(vector<int>adj[],int vis[],int src){
    vis[src]=1;
    queue<pair<int,int>>q;
    q.push({src,-1});
    while(!q.empty()){
        int node= q.front().first;
        int parent= q.front().second;
        q.pop();
        for(auto adjNode: adj[node]){
            if(!vis[adjNode]){
                vis[adjNode]=1;
                q.push({adjNode,node});

            }
            else if(adjNode!= parent){
                return true;
            }
        }
    }
    return false;
}
bool isCycle(int V,vector<int>adj[]){
    int vis[V]={0};
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(detect(adj,vis,i)) return true;
        }
    }
    return false;
}
int main(){
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    bool ans = isCycle(4,adj);
    if(ans){
        cout<<"1";
    }else{
        cout<<"0";
    }

}
*/


/*                               Cycle detection Using Dfs                                 */

#include<bits/stdc++.h>
using namespace std;
bool detect(int node,int parent ,int vis[],vector<int>adj[]){
    vis[node]=1;
    for(auto adjNode: adj[node]){
        if(!vis[adjNode]){
            if(detect(adjNode,node,vis,adj)== true) return true;
        }else if(adjNode != parent ){
            return true;
        }
    }
    return false;
}
bool isCycle(int V,vector<int>adj[]){
    int vis[V]={0};
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(detect(i,-1,vis,adj)== true) return true;
        }
    }
    return false;
}
int main(){
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    bool ans = isCycle(4,adj);
    if(ans){
        cout<<"1";
    }else{
        cout<<"0";
    }
}