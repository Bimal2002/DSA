#include<bits/stdc++.h>
using namespace std;
int romanToDecimal(string str){
    unordered_map<char, int> romanMap = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int sum =0;
        for(int i=0;i<str.length();i++){
            if(i+1<str.length() && romanMap[str[i]]<romanMap[str[i+1]]){
                sum += romanMap[str[i+1]]-romanMap[str[i]];
                i++;
            }
            else{
                sum += romanMap[str[i]];
            }
        }
        return sum;
}
int main(){
     string str = "IX";
    cout << romanToDecimal(str) << endl;
    return 0;
}