#include <bits/stdc++.h>
using namespace std;
void dfs(int r, int c, vector<vector<int>> &image, int iniColor, vector<vector<int>> &ans, int dr[], int dc[], int newColor)
{
    int n = image.size(), m = image[0].size();
    ans[r][c] = newColor;
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nc >= 0 && nr < n && nc < m && image[nr][nc] == iniColor && ans[nr][nc] != newColor){
             dfs(nr,nc,image,iniColor,ans,dr,dc,newColor);
        }
    }
   
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int iniColor = image[sr][sc];
    vector<vector<int>> ans = image;
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    dfs(sr, sc, image, iniColor, ans, dr, dc, newColor);
    return ans;
}

int main()
{
    vector<vector<int>> grid = {
        {1, 1, 1},
        {0, 1, 1},
        {1, 1, 1}};
    vector<vector<int>>ans =floodFill(grid,1,1,2);   
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    } 
}