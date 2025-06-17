#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>&st,int x){
    if(st.empty() || st.top() <= x){
        st.push(x);
        return ;
    } 

    int temp = st.top();
    st.pop();
    insertAtBottom(st,x);
    st.push(temp);
}
void sortStack(stack<int>&st){
    if(st.empty()) return;

    int top = st.top();
    st.pop();
    sortStack(st);
    insertAtBottom(st,top);
}
void insertAtBottom1(stack<int>&st,int x){
    if(st.empty()){
        st.push(x);
        return ;
    }
    int top = st.top();
    st.pop();
    insertAtBottom1(st,x);
    st.push(top);
}



// Delete Middle element
void deleteMiddleHelper(stack<int>&st,int curr,int mid){
    if(curr == mid){
        st.pop();
        return ;
    }
    int temp = st.top();
    st.pop();
    deleteMiddleHelper(st,curr+1,mid);
    st.push(temp);
}

void deleteMiddle(stack<int>&st){
    int n =st.size();
    int mid = n/2;
    deleteMiddleHelper(st,0,mid);
}



// Delete K-th Element from the Bottom of a stack 
// k-th from bottom means (n-k-1)-th from top
int countElements(stack<int>&s){
    if(s.empty()) return 0;

    int temp = s.top();s.pop();
    int cnt = 1 + countElements(s);
    s.push(temp);
    return cnt;
}

void deleteKthFromTop(stack<int>&s,int k){
    if(k==0){
        s.pop();
        return;
    }

    int temp = s.top();
    s.pop();
    deleteKthFromTop(s,k-1);
    s.push(temp);
}

void deleteKthFromBottom(stack<int>&s ,int k){
    // int n = countElements(s);
    int n = s.size();
    int targetFromTop =n-k-1;
    deleteKthFromTop(s,targetFromTop);
}
int main(){
    stack<int>st;
    st.push(2);
    st.push(4);
    st.push(1);
    st.push(3);
    // sortStack(st);

    // insert element at bottom 
    // insertAtBottom1(st,5);
    // cout<<st.top();
    
    deleteMiddle(st);
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}