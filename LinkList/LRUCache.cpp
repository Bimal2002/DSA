#include<bits/stdc++.h>
using namespace std;
class LRUCache{
    private:
    struct Node{
        int key,value;
        Node*next,*prev;
        Node(int k,int v){
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };
    unordered_map<int,Node*>mp;
    int capacity;
    Node* head,*tail;

    void addToHead(Node* node){
        Node* temp = head ->next;
        node->next = temp;
        node->prev = head;
        temp->prev = node;
        head->next= node;
    }

    void removeNode(Node* node){
        Node* p = node->prev;
        Node* n = node->next;
        p->next = n;
        n->prev = p;
    }
    public :
    LRUCache(int cap){
        capacity  = cap;
        // dummt head and tail 
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key){
        if(mp.find(key)== mp.end()){
            return -1;
        }
        Node* node= mp[key];
        removeNode(node);
        addToHead(node);
        return node->value;
    }

    void put(int key,int val){
        if(mp.find(key)!= mp.end()){
            Node* node = mp[key];
            node->value = val;
            removeNode(node);
            addToHead(node);
            return;
        }

        //create new NODE 
        Node* node= new Node(key,val);
        mp[key]= node;
        addToHead(node);

        if(mp.size()>capacity){
            Node* lru = tail->prev;
            removeNode(lru);
            mp.erase(lru->key);
            delete lru;
        }

    }
};

int main(){

}