#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

// Tree Node Structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 1. STANDARD LEVEL ORDER TRAVERSAL (BFS)
// Visits nodes level by level from left to right
void levelOrderTraversal(TreeNode* root) {
    if (!root) return;
    
    queue<TreeNode*> q;
    q.push(root);
    
    cout << "Level Order Traversal: ";
    
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        
        cout << current->val << " ";
        
        // Add children to queue (left first, then right)
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    cout << endl;
}

// 2. LEVEL ORDER WITH LEVEL SEPARATION
// Shows each level on a separate line
void levelOrderWithLevels(TreeNode* root) {
    if (!root) return;
    
    queue<TreeNode*> q;
    q.push(root);
    
    cout << "Level Order (with level separation):" << endl;
    
    while (!q.empty()) {
        int levelSize = q.size(); // Number of nodes in current level
        
        cout << "Level: ";
        for (int i = 0; i < levelSize; i++) {
            TreeNode* current = q.front();
            q.pop();
            
            cout << current->val << " ";
            
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        cout << endl;
    }
}

// 3. SPIRAL LEVEL ORDER TRAVERSAL (Method 1: Using Two Stacks)
// Alternates direction: left-to-right, then right-to-left
void spiralTraversalTwoStacks(TreeNode* root) {
    if (!root) return;
    
    stack<TreeNode*> s1; // For left to right
    stack<TreeNode*> s2; // For right to left
    
    s1.push(root);
    
    cout << "Spiral Traversal (Two Stacks): ";
    
    while (!s1.empty() || !s2.empty()) {
        // Process left to right (odd levels: 1, 3, 5...)
        while (!s1.empty()) {
            TreeNode* current = s1.top();
            s1.pop();
            cout << current->val << " ";
            
            // For left-to-right, push left child first, then right
            if (current->left) s2.push(current->left);
            if (current->right) s2.push(current->right);
        }
        
        // Process right to left (even levels: 2, 4, 6...)
        while (!s2.empty()) {
            TreeNode* current = s2.top();
            s2.pop();
            cout << current->val << " ";
            
            // For right-to-left, push right child first, then left
            if (current->right) s1.push(current->right);
            if (current->left) s1.push(current->left);
        }
    }
    cout << endl;
}

// 4. SPIRAL LEVEL ORDER TRAVERSAL (Method 2: Using Queue + Flag)
// Uses a single queue with a direction flag
void spiralTraversalQueueFlag(TreeNode* root) {
    if (!root) return;
    
    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;
    
    cout << "Spiral Traversal (Queue + Flag): ";
    
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> levelNodes(levelSize);
        
        // Collect all nodes at current level
        for (int i = 0; i < levelSize; i++) {
            TreeNode* current = q.front();
            q.pop();
            
            // Decide index based on direction
            int index = leftToRight ? i : levelSize - 1 - i;
            levelNodes[index] = current->val;
            
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        
        // Print level nodes
        for (int val : levelNodes) {
            cout << val << " ";
        }
        
        // Toggle direction for next level
        leftToRight = !leftToRight;
    }
    cout << endl;
}

// 5. SPIRAL TRAVERSAL RETURNING 2D VECTOR
// Returns spiral traversal as vector of vectors (each inner vector is a level)
vector<vector<int>> spiralLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;
    
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> level(levelSize);
        
        for (int i = 0; i < levelSize; i++) {
            TreeNode* current = q.front();
            q.pop();
            
            int index = leftToRight ? i : levelSize - 1 - i;
            level[index] = current->val;
            
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        
        result.push_back(level);
        leftToRight = !leftToRight;
    }
    
    return result;
}

// Helper function to create sample tree
TreeNode* createSampleTree() {
    /*
    Sample Tree:
           1
          / \
         2   3
        / \ / \
       4  5 6  7
      /
     8
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    
    return root;
}

int main() {
    TreeNode* root = createSampleTree();
    
    cout << "Tree Structure:" << endl;
    cout << "       1" << endl;
    cout << "      / \\" << endl;
    cout << "     2   3" << endl;
    cout << "    / \\ / \\" << endl;
    cout << "   4  5 6  7" << endl;
    cout << "  /" << endl;
    cout << " 8" << endl << endl;
    
    // Standard level order traversal
    levelOrderTraversal(root);
    cout << endl;
    
    // Level order with level separation
    levelOrderWithLevels(root);
    cout << endl;
    
    // Spiral traversals
    spiralTraversalTwoStacks(root);
    spiralTraversalQueueFlag(root);
    
    // Spiral traversal returning 2D vector
    cout << "\nSpiral Traversal (2D Vector Result):" << endl;
    vector<vector<int>> spiral = spiralLevelOrder(root);
    for (int i = 0; i < spiral.size(); i++) {
        cout << "Level " << i + 1 << ": ";
        for (int val : spiral[i]) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/*
EXPECTED OUTPUT:
================
Level Order Traversal: 1 2 3 4 5 6 7 8 

Level Order (with level separation):
Level: 1 
Level: 2 3 
Level: 4 5 6 7 
Level: 8 

Spiral Traversal (Two Stacks): 1 2 3 7 6 5 4 8 
Spiral Traversal (Queue + Flag): 1 2 3 7 6 5 4 8 

Spiral Traversal (2D Vector Result):
Level 1: 1 
Level 2: 2 3 
Level 3: 7 6 5 4 
Level 4: 8 

TIME COMPLEXITY:
- Level Order: O(n) where n is number of nodes
- Spiral Order: O(n) where n is number of nodes

SPACE COMPLEXITY:
- Level Order: O(w) where w is maximum width of tree
- Spiral Order: O(w) where w is maximum width of tree
*/