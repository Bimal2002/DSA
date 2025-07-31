#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
         Node* links[26];
         bool isEnd;
         Node(){
            for(int i=0;i<26;i++){
                links[i]=NULL;
            }
            isEnd=false;
         }

         bool containKey(char ch){
            return links[ch-'a']!=NULL;
         }

         Node* put(char ch,Node* node){
            return links[ch-'a']=node;
         }
         
         Node* get(char ch){
            return links[ch-'a'];
         }
         void setEnd(){
            isEnd = true;
         }
         bool isEndNode(){
            return isEnd;
         }
};
class Trie{
    private:
        Node* root;
    public:  
         Trie(){
            root = new Node();
         }  

         void insert(string word){
            Node* node = root;
            for(int i=0;i<word.size();i++){
                char ch = word[i];
                if(!node->containKey(ch)){ // if not contain key then put new node
                    node->put(ch,new Node());
                }
                node= node->get(ch);
            }
            node->setEnd();
         }

         bool search(string word){
            Node* node = root;
            for(int i=0;i<word.size();i++){
                char ch = word[i];
                if(!node->containKey(ch)){
                    return false;
                }
                node = node->get(ch);
            }
            return node->isEndNode();
         }

         bool startsWith(string prefix){
            Node* node = root;
            for(int i=0;i<prefix.size();i++){
                char ch = prefix[i];
                if(!node->containKey(ch)){
                    return false;
                }
                node = node->get(ch);
            }
            return true;
         }
};


int main(){
    Trie trie;
    trie.insert("striver");
    trie.insert("striving");
    trie.insert("string");
    trie.insert("strike");

    cout << "Search 'strawberry': " << (trie.search("strawberry") ? "True" : "False") << endl;
    cout << "Search 'strike': " << (trie.search("strike") ? "True" : "False") << endl;
    cout << "Prefix 'stri' exists: " << (trie.startsWith("stri") ? "True" : "False") << endl;

    return 0;

}