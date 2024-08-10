#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* insertNodeInBST(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }
    
    // insert in left
    if (root->data > data) {
        root->left = insertNodeInBST(root->left, data);
    } else {
        root->right = insertNodeInBST(root->right, data);
    }

    return root;
}

void takeInput(Node* &root) {
    int data;
    cin >> data;
    while (data != -1) {
        root = insertNodeInBST(root, data);
        cin >> data;
    }
}

// In-order Traversal (LNR)
void inOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    // Traverse left
    inOrderTraversal(root->left);
    // Visit root
    cout << root->data << " ";
    // Traverse right
    inOrderTraversal(root->right);
}

// Find Node
bool findNode(Node* root, int target) {
    if (root == NULL) {
        return false;
    }

    if (root->data == target) {
        return true;
    }

    // Search in left
    if (root->data > target) {
        return findNode(root->left, target);
    } else {  // Search in right
        return findNode(root->right, target);
    }
}

// Find minimum element
int findMin(Node* root) {
    Node* temp = root;
    if (root == NULL) {
        return -1; // or some other error value or throw exception
    }

    while (temp->left != NULL) {
        temp = temp->left;
    }

    return temp->data;
}

// Find maximum element
int findMax(Node* root) {
    Node* temp = root;
    if (root == NULL) {
        return -1; // or some other error value or throw exception
    }

    while (temp->right != NULL) {
        temp = temp->right;
    }

    return temp->data;
}
Node* deleteNodeInBst(Node* root,int target){
    if(root == NULL){
        return root;
    }

    if(root->data == target){
        if(root->left == NULL && root->right == NULL){
            return NULL;
        }
        else if(root->left != NULL && root->right == NULL){
            Node* child = root->left;
            return child;
        }
        else if(root->left == NULL && root->right != NULL){
            Node* child = root->right;
            return child;
        }
        else {
            int inorderPre = findMax(root->left);
            root->data = inorderPre;
            root->left = deleteNodeInBst(root->left,inorderPre);
            return root;
        }
    }
    else if(root->data <target){
          root->right = deleteNodeInBst(root->right,target);
    }else{
        root->left = deleteNodeInBst(root->left,target);
        
    }

    return root;
}


// check it is a BST or Not
bool solve(Node* root, int lb , int ub){
    if(root == NULL ){
        return true;
    }

    if( root->data > lb && root->data < ub){
        bool leftAns = solve(root->left,lb,root->data);
        bool rightAns = solve(root->right,root->data,ub);
        return leftAns && rightAns;
    }else{
        return false;
    }
}
bool isValidBST(Node* root){
    long long int lb = -2^32;
    long long int ub = 2^32;
    bool ans = solve(root, lb,ub);
    return ans;
}


// LCA for BST

Node* lca(Node* root, Node* p ,Node*q){
    if(root == NULL){
        return NULL;
    }
    // case-1  root   
    //          /
    //         /\
    //         p q 

    //           root                       p and q node is present in left subtree
    //          /
    //         /\
    //         q p 
    if(root->data > p->data  && root->data > q->data){
        return lca(root->left,p,q);
    }

    // case-2 
    //      root   
    //         \ 
    //         /\
    //         p q 

    //      root                       p and q node is present in right subtree
    //         \
    //         /\
    //         q p 
    else if(root->data < p->data && root->data < q->data){
        return lca(root->right,p,q);
     // case-3
    //        root   
    //         /\
    //         p q 
    }else{  // 
        return root;
    }
}

// Kth Smallest Element in BST
int kthSmallestInBST(Node* root,int &k){
    if(root== NULL ){
        return -1;
    }

    int leftAns = kthSmallestInBST(root->left,k);
    if(leftAns != -1){
        return leftAns;
    }
    k--;

    if(k==0){
        return root->data;
    }

    int rightAns = kthSmallestInBST(root->right,k);
    return rightAns;
}

// build BST from inOrder array
Node* buildBSTUsingInOrder(int inorder[],int s,int e){

    if(s>e) return NULL;

    int mid = s + (e-s)/2;
    int element = inorder[mid];
    // create root element
    Node* root = new Node(element);
    // leftSubTree 
    root->left = buildBSTUsingInOrder(inorder,s,mid-1);
    // rightSubTree
    root->right = buildBSTUsingInOrder(inorder,mid+1,e);
    return root;

}



void solve(Node* root, vector<int>& inOrder){
    if(root == NULL){
        return ;
    }
    // L 
    solve(root->left ,inOrder);
    // Node
    inOrder.push_back(root->data);
    // R
    solve(root->right,inOrder);
}

// Target Sum
bool findTarget(Node* root,int k){
    vector<int>inOrder;
    solve(root,inOrder);

    int s =0;
    int e = inOrder.size()-1;
    while(s>e){
        int sum = inOrder[s]+inOrder[e];
        if(sum == k ){
            return true;
        }
        else if(sum > k){
            e--;
        }else{
            s++;
        }
    }
    return false;
}

// BST into DLL
void convertBSTtoDLL(Node* root,Node* & head){
    if(root == NULL ){
        return ;
    }
    convertBSTtoDLL(root->right,head);
    root->right = head;
    if(head != NULL){
        head->left = root;
    }
    head = root;
    convertBSTtoDLL(root->left,head);
}
int main() {
    Node* root = NULL;
    cout << "Enter elements to insert into BST (-1 to stop): ";
    takeInput(root);

    cout << "In-order Traversal of the BST: ";
    inOrderTraversal(root);
    cout << endl;

    int target;
    cout << "Enter the value to find in the BST: ";
    cin >> target;
    if (findNode(root, target)) {
        cout << target << " found in the BST." << endl;
    } else {
        cout << target << " not found in the BST." << endl;
    }

    cout << "Minimum value in the BST: " << findMin(root) << endl;
    cout << "Maximum value in the BST: " << findMax(root) << endl;

    return 0;
}
