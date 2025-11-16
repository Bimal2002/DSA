#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int N,M,X;
vector<vector<int>>dist;
vector<vector<int>>dp;
int tsp(int mask,int u){
    //if already computed
    if(dp[mask][u]!=-1) return dp[mask][u];

    int ans = INF;
    //try going to every node v not yet visited
    for(int v=0;v<N;v++){
        if(mask &&(1<<v)) continue;
        if(dist[u][v]==INF) continue;

        int newMask = mask |(1<<v);
        int nextCost = tsp(newMask,v);
        if(nextCost !=INF){
            ans = min(ans,dist[u][v]+nextCost);
        }
    }
    return dp[mask][u]= ans;
}
int main(){
    cin>>N>>M>>X;
    dist.assign(N,vector<int>(N,INF));
    for(int i=0;i<N;i++) dist[i][i]=0;

    for(int i=0;i<M;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        dist[u][v]= min(dist[u][v],w);
        dist[v][u] = min(dist[v][u],w);
    }
    // Floyd-warshall to get shortest paths
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(dist[i][k]<INF && dist[k][j]<INF){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }

    int maxMask = 1 <<N;
    dp.assign(maxMask,vector<int>(N,-1));

    //base case : starting at node 0 with only it visited
    dp[1<<0][0] = 0;
    
    // Run tsp recursively for all subsets
    for(int mask=1;mask<maxMask;mask++){
        for(int u=0;u<N;u++){
            if(!(mask &(1<<u))) continue;
            tsp(mask,u);
        }
    }

    // step 3: check with subsets can return to 0 with cost <=x
    int ans = 1;
    for(int mask =1 ; mask <maxMask;mask++){
        for(int u=0;u<N;u++){
            if(dp[mask][u]==-1 || dp[mask][0] <= X){
                ans = max(ans , __builtin_popcount(mask));
            }
        }
    }
    cout<<ans<<endl;
    
}