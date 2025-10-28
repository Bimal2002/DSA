// Brute Force
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long solve(int N, vector<int>& A) {
    long long maxScore = 0;
    
    // For each possible K
    for (int k = 0; k < N; k++) {
        long long score = 0;
        // Sum of XORs between A[k] and all elements
        for (int i = 0; i < N; i++) {
            score += (A[i] ^ A[k]);
        }
        maxScore = max(maxScore, score);
    }
    
    return maxScore;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    cout << solve(N, A) << endl;
    
    return 0;
}


// Better Approach
#include<bits/stdc++.h>
using namespace std;
long long solve(vector<int>&arr){
    vector<int>count1(32,0);
    for(int num : arr){
        for(int bit =0 ; bit<32;bit++){
            if((num & (1<<bit)) !=0){
                count1[bit]++;
            }
        }
    }
    long long Maxscore =0;
    int n = arr.size();
    for(int k=0;k<n;k++){
       long long score =0;
       int curr = arr[k];
       for(int bit =0; bit <32;bit++){
           int bitVal = (1LL<<bit);
           if((curr & bitVal) != 0){
               score += (n - count1[bit])* bitVal;
           }else{
               score += (count1[bit])* bitVal;
           }
       }

       Maxscore = max(Maxscore,score);
    }
    return Maxscore;
}
int main(){
    int N;
    cin>>N;
    vector<int>arr;
    for(int i=0;i<N;i++){
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    int score = solve(arr);
    cout<<score<<" ";
}