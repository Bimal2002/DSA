#include<bits/stdc++.h>
using namespace std;
int precedence(char c){
    if(c=='^') return 3;
    else if(c=='*' || c=='/') return 2;
    else if(c=='+'|| c=='-') return 1;
    else
         return -1;

}
string infixToPostfix(string s){
    stack<int>st;
    string res;
    for(char c : s){
        // if operands-> add to result
        if(isalnum(c)){
            res += c;
        }
        // if c=='(' then push in stack
        else if(c=='('){
            st.push(c);
        }
        // if c == ')' pop utill found '('
        else if(c == ')'){
            while(!st.empty() && st.top()!='('){
                res += st.top();
                st.pop();
            }
            // for open bracket
            st.pop();
        }
        // operator
        else {
            while(!st.empty() && precedence(st.top())>=precedence(c) && !(c=='^' && st.top()=='^')){
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}

string infixToPrefix(string s){
    // Reverse the infix
    //Infix to postfix
    // reverse the ans
    stack<char>st;
    string res;
    //step-1
    reverse(s.begin(),s.end());

    // step -2
    for(char c: s){
        // if operands , add to res
        if(isalnum(c)){
            res += c;
        }
        // if c=='('
        else if(c =='('){
            st.push(c);
        }
        // if c==')' , pop the stack utill found ( , and during this time add c to res
        else if(c==')'){
            while(!st.empty() &&  st.top()=='('){
                res += st.top();
                st.pop();
            }
            // when opening backect found
            st.pop();
        }else{
            while (!st.empty() && precedence(c) < precedence(st.top())){
             res += st.top();
             st.pop();

            }
            st.push(c);

            
        }
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }

     // step=3
    reverse(res.begin(),res.end());
    return res;


}
int main(){
    string s ="a+b*c-d^e^f";
    string ans = infixToPostfix(s);
    cout<<"Infix To Postfix : " << ans<<endl;

    string ans1 = infixToPrefix(s);
    cout<<"Infix to Prefix : "<< ans1;

}