#include<bits/stdc++.h>
using namespace std;
class Node{
   public: 
    int data;
    Node* left ;
    Node* right;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


Node* buildTree(int data){
    if(data == -1){
        return NULL;
    }

    Node* root = new Node(data);
    int leftNode;
    cout<<"Enter the data of left of "<<data <<endl;
    cin>>leftNode;
    root->left = buildTree(leftNode);

    int rightNode;
    cout<<"Enter the data of right of "<<data <<endl;
    cin>>rightNode;

    root->right = buildTree(rightNode);
    return root;

}
void LevelOrderTraversal(Node* root){
    if(root == NULL){
        return ;
    }

    queue<Node*>q;
    q.push(root);
    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }

    }
    cout<<endl;

    
}
// InOrder Traversal LNR
void InOrder(Node* root){
    if(root == NULL){
        return ;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);


}

// PreOrder Traversal NLR
void PreOrder(Node* root){
    if(root == NULL){
        return ;
    }

    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);


}


// PostOrder Traversal LRN
void PostOrder(Node* root){
    if(root == NULL){
        return ;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";



}
int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    int ans = 1 + max(lh,rh);
    return ans;
}
int diameter(Node* root){
    if(root == NULL){
        return 0;
    }

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left)+height(root->right);
    int ans = max(op1,max(op2,op3));
    return ans;
}
bool balanceTree(Node* root){
    if(root == NULL){
        return true;
    }

    int lh = balanceTree(root->left);
    int rh = balanceTree(root->right);
    int diff = abs(lh-rh);
    bool ans1 = (diff <=1);
    bool leftAns = balanceTree(root->left);
    bool rightAns = balanceTree(root->right);
    if(leftAns && rightAns && ans1){
        return true;
    }else{
        return false;
    }
}

int convertToSumTree(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftAns = convertToSumTree(root->left);
    int rightAns = convertToSumTree(root->right);
    root->data = root->data + leftAns +rightAns;
    return root->data;
}
Node* LCA(Node* root,Node* p, Node* q){
    if(root== NULL){
        return NULL;
    }

    if(root->data == p->data){
        return p;
    }
    if(root->data == q->data){
        return q;
    }

    Node* leftAns = LCA(root->left , p,q);
    Node* rightAns = LCA(root->right,p,q);

    if(leftAns == NULL && rightAns == NULL){
        return root;
    }
    else if(leftAns != NULL && rightAns == NULL){
        return leftAns;
    }

    else if(leftAns == NULL && rightAns != NULL){
        return rightAns;
    }
    else{
        return root;
    }
}
bool kthAncestor(Node* root,int p ,int & k){
    if(root == NULL){
        return false;
    }
    if(root->data == p){
        return true;
    }

    bool leftAns = kthAncestor(root->left,p,k);
    bool rightAns = kthAncestor(root->right,p,k);
    if(leftAns || rightAns){
        k--;
    }
    if(k==0){
        cout<<" Ans  : "<<root->data;
        k=-1;
    }
    return leftAns || rightAns;
}
//Path- II sum 
void solve(Node* root,int Currsum, vector<int>&path,int targetSum,vector<vector<int>>&ans){
    if(root == NULL){
        return ;
    }
    if(root->left == NULL && root->right == NULL){
        // consider to leaf node
        path.push_back(root->data);
        Currsum += root->data;

        if(Currsum ==  targetSum){
            ans.push_back(path);
        }
        // consider others solutions
        path.pop_back();
        Currsum -= root->data;
        return;
    }


    // include 
    path.push_back(root->data);
    Currsum += root->data;

    // left node
    solve(root->left,Currsum,path,targetSum,ans);
    // right node
    solve(root->right,Currsum,path,targetSum,ans);

    // backtrack
    path.pop_back();
    Currsum -= root->data;
 

}
vector<vector<int>>PathSum(Node* root,int targetSum){
    vector<vector<int>>ans;
    int sum =0;
    vector<int>path;
    solve(root,sum,path,targetSum,ans);
    return ans;
}

// Build the Tree using InOrder and PreOrder Traversal array
int findPos(int element,int inOrder[],int n){
    for(int i=0;i<n;i++){
        if(inOrder[i]== element){
            return i;
        }
    }
    return -1;
}
Node* buildTreeUsingInOrderPreOrder(int inOrder[],int preOrder[],int size,int & preIndex,int inOrderStart,int inOrderEnd){
    if(preIndex >= size || inOrderStart > inOrderEnd){
          return NULL;
    }
    int element = preOrder[preIndex++];
    Node* root = new Node(element);


    int pos = findPos(element,inOrder,size);
    root->left = buildTreeUsingInOrderPreOrder(inOrder,preOrder,size,preIndex,inOrderStart,pos-1);
    root->right = buildTreeUsingInOrderPreOrder(inOrder,preOrder,size,preIndex,pos+1,inOrderEnd);
    return root;

}

// Build The Tree using Post Order and InOrder Traversal Array 
Node* buildTreeUsingInOrderPostOrder(int inOrder[],int PostOrder[],int size,int &postIndex, int inOrderStart,int inOrderEnd){
    if(postIndex <0 || inOrderStart > inOrderEnd){
        return NULL;
    }
    int element = PostOrder[size-1];
    Node* root = new Node(element );
    int pos = findPos(element,inOrder,size);
    // first right call b/c PostOrder from ending to starting is node psoition
    root->right = buildTreeUsingInOrderPostOrder(inOrder,PostOrder,size,postIndex,pos+1,inOrderEnd);
    // left call 
    root->left = buildTreeUsingInOrderPostOrder(inOrder,PostOrder,size,postIndex,inOrderStart,pos-1);
    
    return root;

}

// Print TopView 
void printTopView(Node* root){
    if(root == NULL){
        return ;
    }

    map<int,int>topNode;
    queue<pair<Node*,int>>q;
    q.push(make_pair(root,0));
    while (!q.empty())
    {
        pair<Node*,int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;
        if(topNode.find(hd)== topNode.end()){
            topNode[hd] = frontNode->data;
        }

        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }

        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }
    for(auto i : topNode){
        cout<<i.second<<endl;
    }
    
}

// bottom View
void BottomView(Node* root){
    if(root == NULL){
        return ;
    }
    map<int,int>topNode;
    queue<pair<Node*,int>>q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*,int>temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;
        // if( topNode.find(hd) == topNode.end()){
        //    topNode[hd]= frontNode->data;
        // }
        topNode[hd]= frontNode->data;

        if(frontNode->left){
            q.push(make_pair(root->left,hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(root->right,hd+1));
        }
    }

    for(auto i :topNode){
        cout<<i.second<<endl;
    }
}

// left View 
void printLeftView(Node* root,int level,vector<int>&ans){
    if(root == NULL){
        return;
    }
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    // left 
    printLeftView(root->left,level+1,ans);
    // right 
    printLeftView(root->right,level+1,ans);
}

// right view
void printRightView(Node* root,int level,vector<int>&ans){
    if(root==NULL){
        return ;
    }

    if(level == ans.size()){
        ans.push_back(root->data);
    }

    // right 
    printRightView(root->right,level+1,ans);
    // left

    printRightView(root->left,level+1,ans);
}






// leftTraversal for boundary traversal
void leftTraversal(Node* root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        return;
    }
    if(root->left){
        leftTraversal(root->left);
    }else{
        leftTraversal(root->right);
    }
    cout<<root->data<<" ";
}


// rightTraversal for boundary traversal
void rightTraversal(Node* root){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right){
        return ;
    }

    if(root->right){
        rightTraversal(root->right);
    }else{
        rightTraversal(root->left);
    }
    cout<<root->data<<" ";
}


// leafTraversal for boundary traversal
void leafTraversal(Node* root){
    if(root == NULL){
        return ;
    }
    if(root->left == NULL && root->right == NULL){
        cout<<root->data<<" ";
    }

    // left 
    leafTraversal(root->left);
    //right 
    leafTraversal(root->right);
}
// BoundaryTraversal
void boundaryTraversal(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    leftTraversal(root->left);
    leafTraversal(root);
    rightTraversal(root->right);
}
int main(){
    int data;
    cin>>data;
    
    Node* root = buildTree(data);
    cout<<"Level Order Traversal : ";

    LevelOrderTraversal(root);
    cout<<"InOrder Traversal : ";

    InOrder(root);
    cout<<endl;
    cout<<"PreOrder Traversal : ";
    PreOrder(root);
    cout<<endl;

    cout<<"PostOrder Traversal : ";
    
    PostOrder(root);
    cout<<endl;




}