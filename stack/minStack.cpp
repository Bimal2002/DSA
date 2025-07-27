#include<bits/stdc++.h>
using namespace std;
class MinStack{
    public:
    vector<pair<int,int>>st;
    MinStack(){

    }
    void push(int val){
        if(st.empty()){
            st.push_back({val,val});
        }else{
            int curMin = min(val,st.back().second);
            st.push_back({val,curMin});
        }
    }

    void pop(){
        if(!st.empty()){
            st.pop_back();
        }else{
            cout<<"Stack underflow";
        }
        
    }

    int top(){
        if(!st.empty()){
            return st.back().first;
        }else{
            cout<<"Stack is empty ";
        }
    }
    int getMin(){
        if(!st.empty()){
            return st.back().second;
        }else{
            cout<<"Stack is empty";
            return -1;
        }
    }
    bool isEmpty(){
        return st.empty();
    }

};

int main() {
    MinStack myStack;  // Create an instance of MinStack
    
    // Push elements onto the stack
    myStack.push(5);
    myStack.push(3);
    myStack.push(8);
    myStack.push(1);
    
    // Example usage of other methods
    cout << "Top element: " << myStack.top() << endl;
    cout << "Minimum element: " << myStack.getMin() << endl;
    
    myStack.pop();
    cout << "After popping, top element: " << myStack.top() << endl;
    cout << "Minimum element: " << myStack.getMin() << endl;
    
    return 0;
}