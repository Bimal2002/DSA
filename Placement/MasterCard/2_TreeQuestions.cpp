#include<bits/stdc++.h>
using namespace std;
struct Node{
      int data;
      Node* left ;
      Node* right;
      Node(int val){
        data = val;
        left = NULL;
        right = NULL;
      }
};
int subtreeSum(Node* root){
    if(root== NULL) return 0;
    return root->data + subtreeSum(root->left) + subtreeSum(root->right);
}
pair<int,int>findSubTreeSums(Node* root){
     int lsum = subtreeSum(root->left);
     int rsum = subtreeSum(root->right);
     return {lsum,rsum};
}
int checkEqualSubtree(Node* root,vector<int>&result){
    if(root== NULL) return 0;
    int lsum = checkEqualSubtree(root->left,result);
    int rsum = checkEqualSubtree(root->right,result);
    if(lsum == rsum && (root->left || root->right)){
        result.push_back(root->data);
    }
    return lsum + rsum + root->data;
    
}
int main(){
//    Node* root= new Node(10);
   int val ;
   cin>>val;
   Node* root = new Node(val);
   cout<<"Enter left node value: ";
   cin>>val;
   if(val!=-1) root->left = new Node(val);
   cout<<"Enter right node";


}
