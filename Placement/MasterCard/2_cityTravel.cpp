#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,M,X;
    cin>>N>>M>>X;
    vector<vector<int>>dist(N,vector<int>(N,INT_MAX));
    for(int i=0;i<N;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        dist[u][v]=min(dist[u][v],w);
        dist[v][u] = min(dist[v][u],w);
    }

    //step-1 : Compute all pairs of shortest distance
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(dist[i][k] <INT_MAX && dist[k][j] <INT_MAX){
                    dist[i][j]= min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }

    // step-2 : DP for TSP variation
    int maxMask = 1 <<N;
    vector<vector<int>>dp(maxMask,vector<int>(N,INT_MAX));
    dist[1<<0][0]=0; // start at node 0

    for(int mask = 1; mask < maxMask ; mask++){
        for(int u=0;u<N;u++){
            if(!(mask&(1<<u)) || dp[mask][u]==INT_MAX) continue;
            for(int v = 0;v<N;v++){
                if(mask&(1<<v)) continue;
                int newMask = mask | (1<<v);
                dp[newMask][v]=min(dp[newMask][v],dp[mask][u]+dist[u][v]);
            }
        }
    }
    // step 3 : check which subsets can be return to 0 with cost <=x
    int ans =1;
    for(int mask =1 ; mask <maxMask;mask++){
        for(int u=0;u<N;u++){
            if(dp[mask][u]==INT_MAX) continue;
            if(dp[mask][u] + dist[u][0]<=X){
              ans = max(ans,__builtin_popcount(mask));
            }
        }
    }
    cout<<ans<<endl;
}