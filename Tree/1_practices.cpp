#include<bits/stdc++.h>
using namespace std;
class Node{
   public: 
   int data ;
   Node* left;
   Node* right;
   Node(int data){
    this->data = data;
    left =NULL;
    right = NULL;
   }
};
Node* builtTree(int data){
    if(data== -1){
        return NULL;
    }
    // create root node
    Node* root = new Node(data);
    int leftData ;
    cout<<"Enter the data left of "<<data<<endl;
    cin>>leftData;
    root->left = builtTree(leftData);
    int rightData;
    cout<<"Enter the data right of "<< data <<endl;
    cin>>rightData;
    root->right = builtTree(rightData);
    return root;
}
void LevelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        cout<<temp->data;
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    
}
int main(){
     int data;
     cin>>data;
     Node* root = builtTree(data);
     cout<<"Level Order Traversal : "<<endl;
     LevelOrderTraversal(root);
}