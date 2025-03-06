// #include<bits/stdc++.h>
// using namespace std;
// int MinimumEffort(vector<vector<int>>& heights){
//     priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
//     int n = heights.size();
//     int m = heights[0].size();

//     vector<vector<int>>dist(n,vector<int>(m,1e9));
//     dist[0][0]=0;
//     pq.push({0,{0,0}});
//     int dx[]={-1,0,1,0};
//     int dy[]={0,-1,0,1};

//     while (!pq.empty())
//     {
//         auto it = pq.top();
//         pq.pop();
//         int diff = it.first;
//         int row = it.second.first;
//         int col = it.second.second;
//         // 
//         if(row == n-1 && col ==  m-1){
//             return diff;
//         }
//         for(int i=0;i<4;i++){
//             int nrow = row + dx[i];
//             int ncol = col + dy[i];
//             if(nrow >=0 && nrow <n && ncol >=0 && ncol <m ){
//                 int newEffort = max(abs(heights[nrow][ncol]-heights[row][col]),diff);

//                 if(newEffort < dist[nrow][ncol]){
//                     dist[nrow][ncol]= newEffort;
//                     pq.push({newEffort,{nrow,ncol}});
//                 }
//             }

//         }
//     }
//     return 0;
    
// }
// int main()
// {
//     // Driver Code.

//     vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};

    

//     int ans = MinimumEffort(heights);

//     cout << ans;
//     cout << endl;

//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
int MinimumEffort(vector<vector<int>>&heights){
       int n = heights.size();
       int m = heights[0].size();
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
       
       vector<vector<int>>dist(n,vector<int>(m,1e9));
       dist[0][0]=0;
       pq.push({0,{0,0}});

       int dr[]={-1,1,0,0};
       int dc[]={0,0,-1,1};

       while(!pq.empty()){
          auto it = pq.top();
          pq.pop();
          int diff = it.first;
          int row = it.second.first;
          int col = it.second.second;
        
          if(row == n-1 && col == m-1){
               return diff;
          }

          for(int i=0;i<4;i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if(nrow >=0 && nrow<n && ncol >=0 && ncol <m ){
                int newEffort = max(abs(heights[nrow][ncol]-heights[row][col]),diff);
                if(newEffort < dist[nrow][ncol]){
                    dist[nrow][ncol]= newEffort;
                    pq.push({newEffort,{nrow,ncol}});
                }
            }
          }
       }
       return 0;
}
int main()
{
    // Driver Code.

    // vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};   // output is 2
    vector<vector<int>> heights{{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}}; // output is 0

    int ans = MinimumEffort(heights);

    cout << ans;
    cout << endl;

    return 0;
}