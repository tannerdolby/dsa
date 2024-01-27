#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Iterative Approach - traverse the tree level by level performing bfs
// O(n) time and O(n) space where n = number of nodes in the BST
vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == NULL) return {};
    // list to store each level of nodes
    vector<vector<int>> levels;
    // queue holding node pointers which we process during the traversal
    queue<TreeNode*> q;
    // add "enqueue" the root node as that will be the first node we process 
    q.push(root);
    while (!q.empty()) {
        // get the size of the queue at each iteration
        int size = q.size();
        // the vector to store each levels node values
        vector<int> level;
        // process elements in the queue
        for (int i=0; i < size; i++) {
            // Store the node at the front of the queue
            // to process it
            TreeNode *curr = q.front();
            // remove it from the front of the queue
            q.pop();

            // add current node value to current level array
            level.push_back(curr->val);

            // if the left or right children arent null
            // add them to the queue for processing
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        // add the level to result list
        levels.push_back(level);
    }
    return levels;
}