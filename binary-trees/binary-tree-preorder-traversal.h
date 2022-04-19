#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

// Recursive approach
// O(n) time and O(d) space
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> traversal;
    preorder(root, traversal);
    return traversal;
}

void preorder(TreeNode* root, vector<int>& traversal) {
    if (root == NULL) return;
    traversal.push_back(root->val);
    preorder(root->left, traversal);
    preorder(root->right, traversal);
}