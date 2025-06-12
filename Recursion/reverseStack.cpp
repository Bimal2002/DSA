#include<bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int>&st,int temp){
    if(st.empty()){
        st.push(temp);
        cout<<"Insert at bottom: "<<temp<<endl;
        return;
    }else{
        int Top = st.top();
        st.pop();
        insertAtBottom(st,temp);
        cout<<"Push back"<<Top<<endl;
        st.push(Top);

    }
}
void Reverse(stack<int>&st){
    if(!st.empty()){
        int temp = st.top();
        cout<<temp<<" ";
        st.pop();
        
        Reverse(st);
        insertAtBottom(st,temp);

    }
}
int main(){
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    // cout<<"Original stack (top to bottom): ";
    // while (!st.empty()) {
    //     cout << st.top() << " ";
    //     st.pop();
    // }
    Reverse(st);

    cout << "Reversed stack (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}