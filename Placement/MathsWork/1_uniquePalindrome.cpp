#include<bits/stdc++.h>
using namespace std;
void expand(string & s,int i,int j,unordered_set<string>&st){
       
    while(i>=0 && j < s.length() && s[i]==s[j]){
        st.insert(s.substr(i,j-i+1));
        i--;
        j++;
    }
}
int findNumOfSubstringPalindrome(string & s){
     unordered_set<string>st;
     for(int i=0;i<s.length();i++){
        expand(s,i,i,st); // odd length
        expand(s,i,i+1,st); // even length
     }
     return st.size();
}
int main(){
    string s;
    cin>>s;
    int ans = findNumOfSubstringPalindrome(s);
    cout<<ans;

}