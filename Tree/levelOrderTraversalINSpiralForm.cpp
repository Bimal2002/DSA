#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

vector<int> findSpiral(Node* root) {
    vector<int> res;
    if (root == nullptr)
        return res;

    stack<Node*> s1; // Current level
    stack<Node*> s2; // Next level

    s1.push(root);

    while (!s1.empty() || !s2.empty()) {

        // Print nodes of current level from s1
        // and push nodes of next level to s2
        while (!s1.empty()) {
            Node* temp = s1.top();
            s1.pop();
            res.push_back(temp->data);

            if (temp->right)
                s2.push(temp->right);
            if (temp->left)
                s2.push(temp->left);
        }

        // Print nodes of current level from s2
        // and push nodes of next level to s1
        while (!s2.empty()) {
            Node* temp = s2.top();
            s2.pop();
            res.push_back(temp->data);

            if (temp->left)
                s1.push(temp->left);
            if (temp->right)
                s1.push(temp->right);
        }
    }
    return res;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    vector<int> res = findSpiral(root);

    for (int x : res)
        cout << x << " ";

    return 0;
}