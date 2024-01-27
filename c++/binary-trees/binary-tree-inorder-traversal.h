#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

// Note: If we have a very large tree as input, say with a depth of 5,000
// the maximum number of frames on the recursion stack will be O(d) where d = depth of the tree
// so if we have large inputs, the recusion may result in a Stack Overflow error, also in the case
// of an extremely unbalanced tree we will recurse down that branch till its leaf which will be O(d)
// frames on the call stack, for a tree that is very unbalanced and has a large depth, it may result
// in a Stack Overflow due to the recursion

// Using an iterative approach would be more preferred if we expect large trees (hopefully balanced)
// aiming for O(n) time and O(n) space
vector<int> inorderTraversal(TreeNode* root) {
    if (root == NULL) return {};
    
    vector<int> traversal;
    stack<TreeNode*> nodeStack;
    TreeNode* curr = root;
    
    while (curr != NULL || !nodeStack.empty()) {
        while (curr != NULL) {
            nodeStack.push(curr);
            curr = curr->left;
        }
        curr = nodeStack.top();
        nodeStack.pop();
        traversal.push_back(curr->val);
        curr = curr->right;
    }
    
    return traversal;
}


// Recursive approach
// O(n) time and O(d) space
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> traversal;
    inorderHelper(root, traversal);
    return traversal;
}
void inorderHelper(TreeNode* root, vector<int>& traversal) {
    // base case
    if (root == NULL) return;

    // traverse left subtree
    inorderHelper(root->left, traversal);

    // visit root node
    traversal.push_back(root->val);

    // traverse right subtree
    inorderHelper(root->right, traversal);
}