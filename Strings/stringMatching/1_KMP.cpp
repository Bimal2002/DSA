#include<bits/stdc++.h>
using namespace std;
vector<int>buildLPS(string pat){
    int m = pat.size();
    int  i=1, len =0;
    vector<int>lsp(m,0);
    while(i<m){
        if(pat[i]==pat[len]){
            len++;
            lsp[i]=len;
            i++;
        }else{
            if(len!=0){
                len = lsp[len-1];

            }else{
                lsp[i]=0;
                i++;

            }
        }
    }
    return lsp;
}
vector<int>KMPsearch(string text,string pat){
     int n = text.size(),m = pat.size();
     vector<int> lps = buildLPS(pat), positions;

    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pat[j]) {
            i++; j++;
        }
        if (j == m) {
            positions.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && text[i] != pat[j]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return positions;

}

// Brute Force
vector<int>bruteForce(string text,string pat){
    vector<int>matches;
    int n = text.size(),m = pat.size();
    for(int i=0;i<n;i++){
        if(text[i]==pat[0]){
            int j=i,k=0;
            while(j<n && k<m && text[j]==pat[k]){
                j++;
                k++;
            }

            if(k==m){
                matches.push_back(i);
            }
        }
    }
    return matches;
}
int main() {
    string text = "ababcababcac";
    string pat = "ababc";
    vector<int> result = KMPsearch(text, pat);
    vector<int>res1 = bruteForce(text,pat);
    cout<<"Brute Force Result :";
    for(int i : result) cout<<i<<" ";
     cout<<endl;
    cout << "Pattern found at indices: ";
    for (int idx : result) cout << idx << " ";
}