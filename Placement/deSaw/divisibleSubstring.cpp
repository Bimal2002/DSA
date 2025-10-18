#include<bits/stdc++.h>
using namespace std;
int countSubstrings(string s){
    int n = s.size();
    int ans =0;
    auto val  = [](char c){
        return (c-'a')/(3+1);
    };
    for(int i=0;i<n;i++){
        int sum =0;
        for(int j=i;j<n;j++){
            sum += val(s[j]);
            int len = j-i+1;
            if(sum % len == 0){
                ans ++;
            }
        }
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    cout<<countSubstrings(s);

}