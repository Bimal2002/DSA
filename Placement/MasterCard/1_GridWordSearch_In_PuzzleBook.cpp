#include<bits/stdc++.h>
using namespace std;
int dr[8]={0,1,1,1,0,-1,-1,-1};
int dc[8]={-1,-1,0,1,1,1,0,-1};
bool isPalindrome(string & s){
     string rs = s;
     reverse(rs.begin(),rs.end());
     return rs == s;

}
bool searchWord(int x,int y,int N,vector<string>&grid,string & word){
    int len = word.size();

    for(int i=0;i<8;i++){
        int k ;

        for(k=0;k<len;k++){
            int nx = x + dr[i]*k;
            int ny = y + dc[i]*k;
            
            // if out of the bound return false
            if(nx<0 || ny <0 || nx >=N || ny >= N){
                
                break;
            }
            if(grid[nx][ny]!= word[k]){
                break;
            }
        }
        if(k == len){
            return true;
        }
    }
    return false;
}
int main(){
    int N;
    cin>>N;
    vector<string>grid;
    for(int i=0;i<N;i++){
        string str;
        cin>>str;
        grid.push_back(str);
    }
    string word;
    cin>>word;
    int cnt =0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j]== word[0]  ){
                if(searchWord(i,j,N,grid,word)){
                  cnt++;
                }
                
            }
        }
    }

    bool isP = isPalindrome(word);
    if(isP){
        cnt = cnt*2;
    }
    cout<<cnt;

}