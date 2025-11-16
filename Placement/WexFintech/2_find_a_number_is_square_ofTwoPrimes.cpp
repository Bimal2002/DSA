#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    if(n<2) return false;
    for(int i=1;i*i<=n;i++){
       if(n%2==0) return false;
    }
    return true;
}
bool solve(int n){
    vector<int>primes;
    for(int i=2;i*i <= n;i++){
       if(isPrime(i)) primes.push_back(i);
    }

    for(int i=0;i< primes.size(); i++){
        for(int j=i;j<primes.size();j++){
            int s = primes[i]*primes[i] + primes[j]*primes[j];
            if(s == n){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    bool ans =  solve(n);
    string s =  ans ==true ? "YES" : "NO";
    cout<<s;

}