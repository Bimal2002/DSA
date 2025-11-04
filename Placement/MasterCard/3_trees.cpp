#include<bits/stdc++.h>
using namespace std;
struct Node{
   int data;
   Node* left;
   Node* right;
   Node(int val){
    data = val;
    left = NULL;
    right = NULL;
   }
};
void insertNode(Node*root,string path,int val){
    Node* curr = root;
    for(int i=0;i<path.size();i++){
        if(path[i]=='L'){
           if(!curr->left)curr->left = new Node(-1);
           curr = curr->left;
        }else{
           if(!curr->right) curr->right = new Node(-1);
           curr = curr->right;
        }
    }
    if(path.back()=='L'){
        curr->left = new Node(val);
    }else{
        curr->right = new Node(val);
    }
}
int digitSum(int x){
    int s=0;
    while(x>0){
         s += x%10;
          x/=10;
    }
    return s;
}
int findSuperNodes(Node* root,int & sum){
    if(!root) return 0;
    if(root->left && root->right){
        int leftsum = digitSum(root->left->data);
        int rightsum = digitSum(root->right->data);
        if(leftsum == rightsum){
            sum += root->data;
        }
    }
    findSuperNodes(root->left,sum);
    findSuperNodes(root->right,sum);
    return sum;
}
int main(){
   int n;
   cin>>n;
   int rootVal;
   cin>>rootVal;
   Node* root = new Node(rootVal);

   for(int i=0;i<n-1;i++){
    string path;
    int val ;
    cin>>path>>val;
    insertNode(root,path,val);

   }
}