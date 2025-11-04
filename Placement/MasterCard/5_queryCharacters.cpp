#include<bits/stdc++.h>
using namespace std;
char findChar(string&A,long long k,long long len){
    if(len == (long long)A.size())
        return A[k];

    long long half = len/2;
    if(k<half){
        return findChar(A,k,half);
    }else{
        long long mirror  = len - 1- k;
        return findChar(A,mirror,half);
    }    
}
int main(){
    string R;
    cin>>R;
    string A;
    for(char c : R){
        if(c!=' '){
            A +=c;
        }
    }
    int q;
    cin>>q;
    vector<long long >queries(q);
    long long maxK= 0;
    for(int i=0;i<q;i++){
        cin>>queries[i];
        maxK = max(maxK,queries[i]);
    }
    long long len = A.size();
    while(len <= maxK){
        len = len*2;
    }
    for(long long k : queries){
        cout<<findChar(A,k,len)<<endl;
    }
}