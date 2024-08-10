#include<bits/stdc++.h>
using namespace std;
string removeDuplicate(string s){
    string ans ="";
    int i=0;
    while(i<s.length()){
        if(ans.size()>0){
            if(ans[ans.length()-1]==s[i]){
                ans.pop_back();
            }else{
                ans.push_back(s[i]);
            }
        }else{
            ans.push_back(s[i]);
        }
        i++;
    }
    return ans;
}
string removeAllTheOccuranceOfaSubString(string s,string part){
     int pos = s.find(part);
     while (pos !=string :: npos)
     {
        s.erase(pos,part.length());
        pos = s.find(part);
     }

     return s;
     
}
int main(){
    string s;
    cin>>s;
    cout<<removeDuplicate(s);

}