#include<bits/stdc++.h>
using namespace std;
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
    string part;
    cin>>part;
    cout<<removeAllTheOccuranceOfaSubString(s,part);
}