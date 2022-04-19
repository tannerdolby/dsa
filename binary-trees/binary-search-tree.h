#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// A node class representing nodes in a binary tree
class Node {
	public:
		int val;
		Node *left;
		Node *right;
		Node() {
			val = 0;
			left = nullptr;
			right = nullptr;
		}
		Node(int n) {
			val = n;
			left = nullptr;
			right = nullptr;
		}
};

// Binary Search Tree
class BinaryTree {
public:
    Node *root;

    Node* insert(Node *root, int val) {
        // base case: when we reach the correct child node 
        // of a leaf, insert the new node
        if (root == NULL) return new Node(val);
        
        // do dfs to find where in the BST we can insert
        if (val < root->val) {
            // insert node into left subtree as a child of leaf node
            root->left = insert(root->left, val);
        } else {
            // insert node into right subtree as a child of leaf node
            root->right = insert(root->right, val);
        }
        
        return root;
    }

    // Average: O(log(n)) time and O(d)=O(log(n)) space
    // Worst: O(n) time and O(d)=O(n) space
    Node* searchBST(Node *root, int target) {
        return searchHelper(root, target);
    }

    Node* searchHelper(Node *root, int target) {
        if (root == NULL) return root;

        if (target == root->val) {
            return root;
        } else if (target < root->val) {
            return searchHelper(root->left, target);
        } else {
            return searchHelper(root->right, target);
        }
    }

    int height(Node *root) {
        if (root == NULL) {
            return -1;
        } else {
            // recursively check the height of left and right subtrees
            // along the longest root-to-leaf path
            int leftSubTreeDepth = height(root->left);
            int rightSubTreeDepth = height(root->right);

            // compare sub tree root-to-leaf paths and add 1 to account for the root node
            return std::max(leftSubTreeDepth, rightSubTreeDepth) + 1;
        }
    }

    void preorderHelper(Node *root, vector<int> &traversal) {
        if (root == NULL) {
            return;
        }
        traversal.push_back(root->val);
        preorderHelper(root->left, traversal);
        preorderHelper(root->right, traversal);
    }

    // O(n) time and O(d) space
    vector<int> preorderTraversal(Node *root) {
        vector<int> traversal;
        preorderHelper(root, traversal);
        return traversal;
    }

    void inorderHelper(Node *root, vector<int> &traversal) {
        if (root == NULL) {
            return;
        }
        inorderHelper(root->left, traversal);
        traversal.push_back(root->val);
        inorderHelper(root->right, traversal);
    }

    // O(n) time and O(d) space
    vector<int> inorderTraversal(Node *root) {
        vector<int> traversal;
        inorderHelper(root, traversal);
        return traversal;
    }

    void postorderHelper(Node *root, vector<int> &traversal) {
        if (root == NULL) {
            return;
        }
        postorderHelper(root->left, traversal);
        postorderHelper(root->right, traversal);
        traversal.push_back(root->val);
    }

    // O(n) time and O(d) space
    vector<int> postorderTraversal(Node *root) {
        vector<int> traversal;
        postorderHelper(root, traversal);
        return traversal;
    }

    // Iterative - O(n) time and O(n) space
    vector<int> levelOrder(Node *root) {
        // create a queue (FIFO) to stored Node* pointers
        vector<int> levelOrderTraversal;
        std::queue<Node*> q;
        q.push(root);

        // while the queue is not empty, process the stored Node* pointers
        while(!q.empty()) {
            Node *curr = q.front();
            q.pop();

            levelOrderTraversal.push_back(curr->val);

            // add left/right child nodes to queue if they exist
            if (curr->left != NULL) q.push(curr->left);
            if (curr->right != NULL) q.push(curr->right);
        }
        return levelOrderTraversal;
    }
};