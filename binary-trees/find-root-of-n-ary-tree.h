#include <vector>
#include <unordered_set>
using namespace std;

struct Node {
    int val;
    vector<Node*> children;
    Node(int x) : val(x) {}
};

// Follow up: Can you solve it O(1) constant space?
// yes!
// since we visit the root node only once
// and the rest of the nodes twice,
// we are looking for the only non-repeated value
// which will be the root node. Summing each nodes value
// and then subtracting it at each child node, we will
// be left with only the root value left, or using XOR
    
Node* findRoot(vector<Node*> tree) {
    int valueSum = 0;
    for (auto node : tree) {
        valueSum += node->val;
        if (node->children.size() > 0) {
            for (auto child : node->children) {
                valueSum -= child->val;
            }
        }
    }
    
    for (auto node : tree) {
        if (node->val == valueSum) {
            return node;
        }
    }
    
    return nullptr;
}

// Using XOR to obtain the only non-repeated node value
Node* findRoot(vector<Node*> tree) {
    int x = 0;
    for (auto node : tree) {
        x ^= node->val;
        if (node->children.size() > 0) {
            for (auto child : node->children) {
                x ^= child->val;
            }
        }
    }
    for (auto node : tree) {
        if (node->val == x) {
            return node;
        }
    }
    return nullptr;
}

// Intuition Approach store all nodes with a parent in a hash set or hash map
// and then iterate through the input tree searching for the child node
// value that doesnt exist in the set, as this will be the node 
// without a parent, and this node represents the root node

// O(N) time and O(N) space
Node* findRoot(vector<Node*> tree) {
    if (tree.size() == 0) return nullptr;
    unordered_set<int> childNodes;
    for (auto node : tree) {
        // if we find a parent node, add all of the children to hash set
        if (node->children.size() > 0) {
            for (auto child : node->children) {
                childNodes.insert(child->val);
            }
        }
    }
    for (auto node : tree) {
        if (childNodes.find(node->val) == childNodes.end()) {
            return node;
        }
    }
    return nullptr;
}