#include<bits/stdc++.h>
using namespace std;

void backtrack(string current,int open,int close,vector<string>& result){

    if(open == 0 && close ==0){
        result.push_back(current);
        return ;
    }
    if(open>0){
        backtrack(current+'(' ,open-1,close,result);

    }
    if(close > open ){
        backtrack(current+')', open,close-1,result);
    }
}
vector<string> generateParenthesis(int n){
    vector<string>result;
    backtrack("",n,n,result);
    return result;
}

bool isValidParentheses(string s){
    int balance = 0;

    for(char ch : s){
        if(ch == '('){
            balance++;
        }else if(ch == ')'){
            balance--;
            if(balance <0) return false;  // More ')' than '('
        }
    }
    return balance == 0;  // all '(' are closed
}
//Valid Parentheses with {, [, (
bool isValid(string s){
    stack<char>st;

    for(char ch : s){
        if(ch == '(' || ch == '{' || ch=='['){
            st.push(ch);
        }else{
            if(st.empty()) return false;

            char top = st.top();
            if((ch ==')' && top == '(') || (ch =='}' && top == '{') || (ch ==']' && top == '[') ){
                st.pop();
            }else{
                return false;
            }
        }
    }
    return st.empty();
}

// Minimum Removals to Make Valid
int minRemoveToMakeValid(string s){
    int open =0, remove =0;
    for(char ch :s){
        if(ch == '('){
            open++;
        }else if(ch == ')'){
            if(open >0){
                open--;  // Match with open '('
            }else{
                remove++; // No open to match
            }
        }
    }
    return remove + open ; // unmatched ')' + unmatched '('
}

// Valid Parenthesis With Wildcards * .   Input: "(*))" Output: true
bool checkValidString(string s){
    int lo =0,hi =0;
    for(char ch :s){
        if(ch == '('){
            lo ++, hi ++;
        }else if(ch == ')'){
            lo --, hi --;
        }else{ // * can be '(' ,')' or empty
            lo --,hi ++;

        }

        if(hi <0) return false;
        if(lo <0 ) lo =0;
    }
    return lo == 0;
}


// Longest Valid Parentheses Substring
int longestValidParenthesis(string s){
    stack<int>st;
    st.push(-1); // base case
    int maxLen =0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            st.push(i);
        }else{
            st.pop();
            if(!st.empty()){
                maxLen = max(maxLen,i-st.top());
            }else{
                st.push(i); // reset the base
            }
        }
    }

}

// Maximum Nesting Depth of Valid Parentheses
int maxDepth(string s){
    int depth =0, maxDepth =0;
    for(char c :s){
        if(c=='('){
            depth++;
            maxDepth = max( maxDepth,depth);
        }else if( c== ')'){
            depth--;
        }
    }

    return maxDepth;
}
int main(){
    // int n = 3;
    // vector<string> combinations = generateParenthesis(n);
    // for(string s : combinations){
    //     cout<<s<<endl;
    // }

    // string s;
    // cin>>s;
    // if(isValidParentheses(s)){
    //     cout<<"Valid"<<endl;
    // }else{
    //     cout<<"InValid"<<endl;
    // }
   
    string s;
    cin>>s;
    if(isValid(s)){
        cout<<"Valid"<<endl;
    }else{
        cout<<"InValid"<<endl;
    }

    cout<<"Min Removals : "<< minRemoveToMakeValid(s)<<endl;

    cout<<"Check Valid  Parenthesis with Wildcards *  : " << checkValidString(s);

}