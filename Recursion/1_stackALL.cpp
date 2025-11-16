#include <bits/stdc++.h>
using namespace std;

void insertAtBottom1(stack<int>&st,int x){
    if(st.empty() || st.top()<=x){
        st.push(x);
        return ;
    }
    int temp = st.top();
    insertAtBottom1(st,x);
    st.push(temp);
}
// Sort stack
void sortStack(stack<int>&st){
    if(st.empty()) return ;

    int temp = st.top();
    sortStack(st);
    insertAtBottom1(st,temp);
}

// Reverse stack
void insertAtBottom(stack<int>&st,int top){
    if(st.empty()){
        st.push(top);
        return ;
    }
    int x = st.top();
    st.pop();
    insertAtBottom(st,x);
    st.push(top);
}
void reverse(stack<int>&st){
    if(st.empty()) return ;
    int top = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st,top);
}
int main()
{
    stack<int> st;
    st.push(2);
    st.push(4);
    st.push(1);
    st.push(3);
    reverse(st);
    // sortStack(st);

    // insert element at bottom
    // insertAtBottom1(st,5);
    // cout<<st.top();

    // deleteMiddle(st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}