#include <bits/stdc++.h>
using namespace std;

// int countNonOverlappingMatches(string s, vector<string>& patterns) {
//     int n = s.size();
//     int count = 0;

//     // Sort patterns by descending length to prioritize longest match first
//     sort(patterns.begin(), patterns.end(), [](const string &a, const string &b) {
//         return a.size() > b.size();
//     });

//     int i = 0;
//     while (i < n) {
//         int matchedLen = 0;

//         // Try to find a pattern starting at current index
//         for (auto &p : patterns) {
//             int len = p.size();
//             if (i + len <= n && s.substr(i, len) == p) {
//                 matchedLen = len; // take longest (since sorted by length)
//                 break;
//             }
//         }

//         if (matchedLen > 0) {
//             count++;
//             i += matchedLen; // move past the matched pattern
//         } else {
//             i++; // no match, move to next index
//         }
//     }
//     return count;
// }

int countNonOverlappingMatches(string& s,vector<string>&patterns){
     int n = s.length();
     sort(patterns.begin(),patterns.end(),[&](string a,string b){
         return a.length() > b.length();
     });

     int i=0;
     int count =0;
     while(i<n){
        int matLen = 0;
        for(auto p : patterns){
            int len = p.size();
            
            if(i+len < n && s.substr(i,len)== p){ // substr(index,len)
                matLen = len;
               
                break;
            }
        }
        if(matLen>0){
            count++;
            i += matLen;
            cout<<i;
        }else{
            i++;
        }

     }
     return count;

}
int main() {
    string s = "abcabcabca";
    vector<string> patterns = {"a", "ab", "abc", "bca"};
    
    cout << countNonOverlappingMatches(s, patterns) << endl;
    return 0;
}
