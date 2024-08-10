#include<bits/stdc++.h>
using namespace std;
string fun(int n){
  string dec="";
  while(n!=0){
    if(n%2==1){
        dec +="1";
    }else{
        dec+="0";
    }
    n=n/2;
  }
  reverse(dec.begin(),dec.end());
  return dec;

}
int main(){
    int num;
    cin>>num;
    string ans = fun(num);
    cout<<ans;

}