#include<bits/stdc++.h>
using namespace std;

void func(int i,int n){
    //base case
    if(i>n){
        return ;
    }

    cout<<i<<endl;
    // rec call
    func(i+1,n);
}

void funcNto1(int i, int n){
      if(i<1)return ;
      cout<<i<<endl;
      funcNto1(i-1,n);
}

int factorial(int n){
    if(n==0) return 1;

    return factorial(n-1)*n;
}

void reverseArr(int arr[],int start , int end){
   if(start >= end) {
     return ;
   }
   swap(arr[start],arr[end]);
   return reverseArr(arr,start+1,end-1);
}


int recAtoi(string s, int i ,bool isNeg ,int res){
   if(s[i]<'0'|| s[i]>'9'){
    return isNeg ? -res : res;
   }

   int digit = s[i]-'0';
   res = res*10+ digit;

   if(res > INT_MAX){
     return isNeg? INT_MIN : INT_MAX;
   }
   return recAtoi(s,i+1,isNeg,res);
}
int myAtoi(string s){
    int i=0;
   bool isNeg = false;
   while(s[i]==' ')i++;
   if(s[i]=='-' || s[i]=='+'){
    if(s[i]=='-'){
         isNeg = true ;
    }
    i++;
   }
   int res =0;
   return recAtoi(s, i ,isNeg ,res);

   
}

int main(){
   int n=4;
//    func(1,n);
//    cout<<factorial(n);
//    funcNto1(n,n);

//   int arr[4]={2,5,3,6};
//   reverseArr(arr,0,3);
//   for(int i=0;i<4;i++){
//     cout<<arr[i]<<" ";
//   }

   string s =" -42";
   myAtoi(s);
   cout<<s;

   

}