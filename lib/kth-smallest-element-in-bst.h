#include <vector>
using namespace std;

// 230. Kth Smallest Element in a BST
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};
    
// O(n) time and O(n) space
int kthSmallest(TreeNode* root, int k) {
    vector<int> inorderVals;
    inorder(root, inorderVals);
    return inorderVals[k-1];
}

// O(n) time and O(d) space
void inorder(TreeNode* root, vector<int>& traversal) {
    if (root == NULL) return;
    inorder(root->left, traversal);
    traversal.push_back(root->val);
    inorder(root->right, traversal);
}