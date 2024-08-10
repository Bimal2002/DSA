#include<bits/stdc++.h>
using namespace std;
bool checkPalindrome(string s,int l,int h){
         while(l<=h){
            if(s[l]!=s[h]){
                 return false;
            }else{
                l++;h--;
            }

         }

         return true;
}
bool palindromeAfterDeletingOneElement(string s){
    int i=0,j= s.length()-1;
    while(i<=j){
        if(s[i]!=s[j]){
           return checkPalindrome(s,i+1,j) || checkPalindrome(s,i,j-1);
        }else{
            i++;j--;
        }
    }
    return true;
}
int main(){
  string s;
  cin>>s;
  if(palindromeAfterDeletingOneElement(s)){
    cout<<"YES";
  }else{
    cout<<"NO";
  }

}

