#include<bits/stdc++.h>
using namespace std;
bool isSafe(int row,int col,vector<string>&board,int n){
    int duprow = row;
    int dupcol = col;
    while(row>=0 && col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        row--;
        col--;
    }
    row = duprow;   
    col = dupcol;
    while(col>=0 && row<n){
        if(board[row][col]=='Q'){
            return false;
        }
        row++;
        col--;
    }
    row = duprow;
    col = dupcol;
    while(col>=0){
        if(board[duprow][col]=='Q'){
            return false;
        }
        col--;
    }
    return true;

}

void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]='Q';
            solve(col+1,board,ans,n);
            board[row][col]='.';
        }
    }
}
vector<vector<string>>nQueen(int n){
    vector<vector<string>>ans;
    vector<string>board(n,string(n,'.'));
    solve(0,board,ans,n);
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<vector<string>>ans =nQueen(n);
    for(auto it:ans){
        for(auto i:it){
            cout<<i<<endl;
        }
        cout<<endl;
    }
}