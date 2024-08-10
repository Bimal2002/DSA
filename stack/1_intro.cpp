#include<bits/stdc++.h>
using namespace std;
int arr[100];
int size=100,top=-1;
void push(int data){
    if((size-top)>1){
        top++;
        arr[top]=data;
    }else{
        cout<<"stack overflow "<<endl;
    }
}
void pop(){
    //stack empty
    if(top==-1){
        cout<<"stack underflow";
    }
    else {
        top--;
    }
}
void getTop(){
    if(top==-1){
        cout<<"stack is empty";
    }else{
        cout<<arr[top];
    }
}
// 2 stacks in an array
// top1=-1 , top2=size , space is avaiable if (top2-top1)>1
int top1=-1,top2=100;// 100 - > means size of arr
void push1(int data){
    if(top2-top1 ==1){
        cout<<"overflow";
    }else{
        top1++;
        arr[top1]=data;
    }
}
// t.c = O(1)
void push2(int data){
    if(top2-top1 == 1){
        cout<<"overflow";
    }else{
        top2--;
        arr[top2]=data;
    }
}
void pop1(){
    if(top1==-1){
        cout<<"underflow";
    }else{
        top1--;
    }
}
void pop2(){
    if(top2==size){
        cout<<"underflow";
    }else{
        top2++;
    }
}
int getSize(){
    return top+1;
}

// reverse the string using stack
void reverse(string str){
    stack<char>s;
    for(int i=0;i<str.length();i++){
        s.push(str[i]);
    }
    while (!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    
}

// Q. find the middle element in the stack
void printMiddle(stack<int>&s,int &totalsize){
    if(s.size()==0){
        cout<<"No element";
        return;
    }
    // base case
    if(totalsize/2 +1 == s.size()){
        cout<<"middle element"<<s.top();
        return;
    }
    int temp=s.top();
    s.pop();
    // recursive call
    printMiddle(s,totalsize);
    // backtracking
    s.push(temp);
}
void solve(stack<int>& s,int target){
     if(s.empty()){
        s.push(target);
        return;
     }
     // step-I
     int topElement = s.top();
     s.pop();

     //recursive call
     solve(s,target);
     // backstrack
     s.push(topElement);
}
void insertAtBottom(stack<int>& s){
    if(s.empty()){
        cout<<"Empty stack";
        return ;
    }
    int target = s.top();
    s.pop();
    solve(s,target);
}

// reverse the stack
void reverseStack(stack<int> &s){
    //empty
    if(s.empty()){
        return;
    }

     int target = s.top();
     s.pop();
     //recursive call
     reverseStack(s);
     solve(s,target);
}

//vlid paranthesis problem
bool isValid(string &s){
    stack<char>st;
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        if(ch == '{' || ch=='['||ch=='('){
            st.push(ch);//push
        }
        // closing bracket
        else {
            if(!st.empty()){
                char topCh = st.top();
                if(ch==')' && topCh =='('){
                    st.top();
                }else if(ch=='}' && topCh=='{'){
                    st.pop();
                }
                else if(ch==']' && topCh=='['){
                     st.pop();
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
        if(st.empty()){
            return true;
        } return false;
    }
}

// Sort a stack
void insertSorted(stack<int>&s,int target){
    //empty
    if(s.empty()){
        s.push(target);
        return;
    }
    // base case
    if(s.top()>=target){
        s.push(target);
        return;
    }
    // normal case
    int topElement = s.top();
    s.pop();
    insertSorted(s,target);// recursive call

    // Backtracking 
    s.push(topElement);

}

// whole the stack sort
void sortStack(stack<int>&s){
    // base case
    if(s.empty()){
        return ;
    }
    //step-I
    int topElement = s.top();
    s.pop();
    //recursive call
    sortStack(s);
    //step-II
    insertSorted(s,topElement);
}

// Remove redundant brackets
int checkRedundancy(string &s){
    // creatation of stack
    stack<char>st;
    for(int i=0;i<s.length();i++){
        //opening breacket or operator 
        if(s[i]=='(' || s[i]=='+' || s[i]=='-'||s[i]=='*' ||s[i]=='/'){
            st.push(s[i]);
        }else{ // closing bracket or charter
            if(s[i]==')'){
                bool flag = true;
                while(!st.empty() && st.top() != '('){
                   if(st.top()=='+' || st.top()=='-'||st.top()=='/'||st.top()=='*'){
                    // false - 
                    flag = false;
                   }
                   st.pop();
                }// either opening bracket or empty stack
                if(!st.empty()){
                    st.pop();
                }
                if(flag == true){
                    return true;
                }


            }

        }
    }
    return false;
}

// longest Valid Paranthesis
int longestvalidParanthesis( string s){
    // create stack
    stack<int>st;
    //initially add / push -1 in stack
    int maxlen=0;
    st.push(-1);
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        // opening bracket 
        if(ch=='('){
            st.push(ch);
        }else{ // closing bracket -> simply pop
           st.pop();
           // stack empty?
           if(st.empty()){
            st.push(i); // because stack is empty so need to push somting for lenght calculate for next parenthesis

            
           }else{
            //not empty
            int len = i-st.top();
            maxlen= max (maxlen,len);
           }


        }
    }

    return maxlen;

}
int main(){
    int data;
    cin>>data;
    push(data);

}