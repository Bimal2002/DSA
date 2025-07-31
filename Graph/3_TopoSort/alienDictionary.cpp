#include<bits/stdc++.h>
using namespace std;
vector<int>topoSort(int V,vector<int>adjLs[]){
      int indegree[V]={0};
      for(int i=0;i<V;i++){
        for(int it : adjLs[i]){
            indegree[it]++;
        }        
      }

      queue<int>q;
      for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
      }
      vector<int>ls;
      while(!q.empty()){
        int node = q.front();
        q.pop();
        ls.push_back(node);
        for(auto it: adjLs[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
      }
      return ls;
}
string AliendDictionary(string dict[],int K,int N){
     vector<int>adjLs[K];
     for(int i=0;i<N-1;i++){
        string s1 = dict[i];
        string s2 = dict[i+1];
        int len = min(s1.length(),s2.length());
        for(int j=0;j<len;j++){
            if(s1[j]!=s2[j]){
                adjLs[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        }      
     }
     vector<int>ans = topoSort(K,adjLs);

     string ans1 ="";
     for(int num : ans){
        ans1 = ans1 + char(num+'a');
     }
     return ans1;



     
}
int main(){
     int N = 5, K = 4;
    string dict[] = {"baa","abcd","abca","cab","cad"};
    string ans = AliendDictionary(dict,K,N);

    for (auto ch : ans)
		cout << ch << ' ';
	cout << endl;
    
}