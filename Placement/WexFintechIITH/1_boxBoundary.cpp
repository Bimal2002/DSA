/*
Problem Statement

You are given an array of positive integers representing the weights of cookies. You need to arrange these cookies into nested boxes such that:

The innermost box contains exactly one cookie (the lightest cookie).

Every other box contains two cookies:

   - The right cookie is heavier than the left one.

Each outer box is wrapped around the previous one, and the cookies inside must be strictly heavier than the cookies inside the inner box.

You must output the arrangement in a string representation of nested boxes.

Example representation:

[32[19]50]

The innermost [19] has cookie 19.

The next box [32 ... 50] contains cookies 32 (left) and 50 (right), wrapping around [19].

and also you would be given a weight W you need to find the box number for it in the above arrangement.

*/

#include<bits/stdc++.h>
using namespace std;
pair<int,string>nestedCookieBoxes(vector<int>&cookies,int w){
    sort(cookies.begin(),cookies.end());
    string  structure = "[" + to_string(cookies[0]) +"]";
    unordered_map<int,int>boxNo;
    boxNo[cookies[0]]=1;
    int level = 2;
    for(int i=1;i<cookies.size();i+=2){
        int left = cookies[i];
        int right = cookies[i+1];
        structure = "["+ to_string(left) + structure + to_string(right)+"]";
        boxNo[left] = level;
        boxNo[right]=level;
        level++;
    }

    int BoxNo =-1;
    if(boxNo.find(w)!= boxNo.end()){
        BoxNo = boxNo[w];
    }
    return {BoxNo,structure};

}
int main(){
    vector<int> cookies = {10, 15, 20, 25, 30};
    int W = 25;

    auto result = nestedCookieBoxes(cookies, W);
    cout << "Structure: " << result.first << endl;
    cout << "Box Number: " << result.second << endl;
    return 0;
}