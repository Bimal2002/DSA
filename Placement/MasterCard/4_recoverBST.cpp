#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right ;
    Node(int x){
        val = x;
        left = right = NULL;
    }
};
class Solution{
    Node* first;
    Node* last;
    Node* middle;
    Node* prev;

    void inorder(Node* root){
        if(!root) return;
        inorder(root->left);
        
        if(prev && root->val <prev->val){
            if(!first){
                first = prev;
                middle = root;
            }else{
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }
    public:
    void recoverBST(Node* root){
        first = middle = last = prev = NULL;
        inorder(root);

        // fix the swapped nodes
        if(first && last){
            swap(first->val,last->val);
        }else if(first && middle){
            swap(first->val,middle->val);
        }
    }
};
// Utility to print inorder
void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}
int main(){
    /*
       Example tree with swapped nodes:
              3
             / \
            1   4
               /
              2
       Swapped nodes: 2 and 3
    */

    Node* root = new Node(3);
    root->left = new Node(1);
    root->right = new Node(4);
    root->right->left = new Node(2);

    cout << "Before recovery (inorder): ";
    printInorder(root);
    cout << "\n";

    Solution s;
    s.recoverBST(root);

    cout << "After recovery (inorder): ";
    printInorder(root);
    cout << "\n";

    return 0;
}