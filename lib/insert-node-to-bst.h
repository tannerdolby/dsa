#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): data(0), left(nullptr), right(nullptr) {};
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {};
};

// Average: O(log(n)) time and O(log(n)) space
// Worst: O(n) time and O(d) space
TreeNode* insertIntoBST(TreeNode* root, int val) {
    return insertHelper(root, val);
}

TreeNode* insertHelper(TreeNode* node, int val) {
    // base case: when we reach the correct child node 
    // of a leaf, insert the new node
    if (node == NULL) return new TreeNode(val);
    
    // do dfs to find where in the BST we can insert
    if (val < node->data) {
        // insert node into left subtree as a child of leaf node
        node->left = insertHelper(node->left, val);
    } else {
        // insert node into right subtree as a child of leaf node
        node->right = insertHelper(node->right, val);
    }
    
    return node;
}