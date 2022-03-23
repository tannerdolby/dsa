#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// A node class representing nodes in a binary tree
class Node {
	public:
		int data;
		Node *left;
		Node *right;
		// default constructor
		Node() {
			data = 0;
			left = NULL;
			right = NULL;
		}
		// parameterized constructor
		Node(int n) {
			data = n;
			left = NULL;
			right = NULL;
		}
};

// Binary Search Tree
class BinaryTree {
public:
    Node *root;

    Node* insert(Node *root, int data) {
        // if the root node pointer is not null, insert nodes
        if (root != NULL) {
            if (data <= root->data) {
                root->left = insert(root->left, data);
            } else {
                root->right = insert(root->right, data);
            }
        } else {
            // root node pointer is null so create a new Node
            return new Node(data);
        }
        // return the root node pointer
        return root;
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
        traversal.push_back(root->data);
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
        traversal.push_back(root->data);
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
        traversal.push_back(root->data);
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

            levelOrderTraversal.push_back(curr->data);

            // add left/right child nodes to queue if they exist
            if (curr->left != NULL) q.push(curr->left);
            if (curr->right != NULL) q.push(curr->right);
        }
        return levelOrderTraversal;
    }
};