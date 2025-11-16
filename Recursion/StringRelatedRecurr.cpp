#include<bits/stdc++.h>
using namespace std;

void removeUtil(string s ,int index ,string & result){
    // base case 
    if(index == s.length()) return;

    char currChar = s[index];

    if(!result.empty() && result.back()== currChar){
        result.pop_back();
    }else{
        result.push_back(currChar);
    }

    removeUtil(s,index+1,result);
}
string removeAdjacentDuplicates(string s){
    string result = "";
    removeUtil(s,0,result);
    return result;
}

void generateBinaryString(int n,string current){
    // base case : if current string length is n , print it
    if(current.length()==n){
        cout<<current<<endl;
        return ;
    }
    // recursive case : try both '0' and '1'
    generateBinaryString(n,current+'0');
    generateBinaryString(n,current+'1');
}

void generateNoConsecutiveOnes(int n ,string current ,int prevBit){
    // base case
    if(current.length()==n){
        cout<<current<<endl;
        return ;
    }
    //always add '0'
    generateNoConsecutiveOnes(n,current+"0",0);

    // add '1' only if previous bit wasn't '1'
    if(prevBit==0){
        generateNoConsecutiveOnes(n,current+"1",1);
    }
}

// Generate Binary Strings with Exactly k 1s
void  generateBinaryStringWithKOnes(int n,int k,string current ,int oneSoFar){
    //base case
    if(current.length()==n){
         if(oneSoFar==k){
            cout<<current<<endl;  
         }
         return ;
    }

    // add '0'
    generateBinaryStringWithKOnes(n,k,current+'0',oneSoFar);

    // add '1'
    if(oneSoFar<k){
        generateBinaryStringWithKOnes(n,k,current+'1',oneSoFar+1);
    }
}

// Generate Binary Strings Where 1s ≥ 0s at Every Prefix
void generatePrefixBalanceBinaryString(int n,int ones ,int zeros,string current){
    // base case
    if(current.length()==n){
        cout<<current<<endl;
        return ;
    }
    

    // add '1' - always allowed 
    generatePrefixBalanceBinaryString(n,ones+1,zeros,current+'1');

    // add '0' - only if 1s are more than 0s
    if(ones > zeros){
        generatePrefixBalanceBinaryString(n,ones,zeros+1,current+"0");
    }
}


// Count the Number of Binary Strings of Length n with 1s ≥ 0s at Every Prefix 
int countPrefixBalancedBinaryStrings(int n,int ones,int zeros){
    // base case 
    if(n==0){
        return 1;
    }

    int cnt =0;
    // op 1: add '1'
    cnt += countPrefixBalancedBinaryStrings(n-1,ones+1,zeros);

    // op 2: add '0' (only if more 1s so far)
    if(ones > zeros){
        cnt += countPrefixBalancedBinaryStrings(n-1,ones,zeros+1);
    }
    return cnt;
}


//
int main(){
    string s1= "abbaca";
    removeAdjacentDuplicates(s1);

    int n ;
    cin>>n;
   
    // generateBinaryString(n,"");
    // generateNoConsecutiveOnes(n,"",0);
    int k =2;
    // generateBinaryStringWithKOnes(n,k,"",0);
    generatePrefixBalanceBinaryString(n,0,0,"");
    
}