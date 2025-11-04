/*
There are A guards and M thieves. Now there are N nodes numbered from 1 to N which are arranged linearly like, 1->2->3->4...... We have an array where it is given distance between 1->2, 2->3, 3->4, and so on. Now for each thief we have two values, The node where it will arrive, and time he will take to arrive at that node. These are given in the question. Now the guards will always start from the node 1. The guards cannot stop at a node and wait to catch the thief. The guards have to keep moving once they start and they can start at any time, for example at t = 1sec, or t=3sec or t=4 sec i.e. whenever we wish. So that means the guard can only catch a thief if the thief has already arrived at the node. Now you can see that each thief will have some waiting time(which maybe zero). Now what you have to do is that for the case which gives the minimum possible sum of waiting time, we have to return an array consisting of waiting time of each thief

*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,M,A;
    cin>>N;
    vector<int>dist(N);
    for(int i=0;i<N;i++) cin>>dist[i];

    cin>>A>>M;
    vector<int>node(M),time(M);
    for(int i=0;i<M;i++) cin>>node[i]>>time[i];

    // prefix travel times
    vector<long long>T(N+1,0);
    for(int i=2;i<=N;i++){
        T[i]= T[i-1]+dist[i-1];
    }

    // find optimal start time
    long long s_opt = LLONG_MIN;
    for(int i=0;i<M;i++){
        s_opt = max(s_opt,(long long)time[i]-T[node[i]]);
    }

    // compute the waiting times
    long long total =0;
    vector<long long>wait(M);
    for(int i=0;i<M;i++){
        wait[i]= max(0LL,s_opt+T[node[i]]-time[i]);
        total += wait[i];
    }
    cout<<"Optimal start time: "<< s_opt<<endl;
    cout<<"waiting times: ";
    for(auto w: wait)cout<<w<<" ";
    cout<<endl<<"Total waiting time = "<< total<<endl;
}