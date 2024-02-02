/* 
Given the fact were provided a Binary Search Tree, the efficient approach will be to traverse the tree and compare the root nodes absolute difference (distance) from the target while keeping track of nodes with lesser "distances" to update the closest value when we encounter a closer node to our target value. Next, we can start comparing the current nodes value to the target, if its less than the target we want to search the right sub-tree for values that are greater than or equal to the root node, if the current nodes value is greater than the target we want to search the left sub-tree for values that are strictly less than the root node.

Doing this, we can eliminate half of the BST (on average) at each step, meaning we traverse the left sub-tree (eliminating the right half) or we traverse the right sub-tree (eliminating the left half) while keeping track of the closest node and updating it when we find nodes closer to the target.

For the BST you've provided 5 4 9, it indeed satisfies the requirements of a BST:

all values left of the root node are strictly less than the root node
all values right of the root node are greater than or equal to the root node
each parent node can only have a maximum of two children
  5
 / \
4   9
and for context a node in the BST will have structure:

struct Node {
  int data;
  Node *left;
  Node *right;
  Node() { data = 0; left = right = nullptr; };
  Node(int val) { data = val; left = right = nullptr; };
}
Below are a few C++ solutions but the logic can be utilized with Java syntax quite easily.

Recursive approach performs on average at O(log(n)) time and O(log(n)) space as we are recursively calling minDiffHelper and those calls or "frames" are added to the call stack which takes up space.
*/

// On average: O(log(n)) time and O(log(n)) space
// Worst case: O(n) time and O(n) space
// where n = number of nodes in the tree

int minDiffHelper(Node *root, int target, int closest);

int minDiff(Node *root, int target) {
    return minDiffHelper(root, K, root->data);
}

int minDiffHelper(Node *root, int target, int closest) {
    if (abs(target-closest) > abs(target-root->data)) {
        closest = root->data;
    }
    if (root->left != nullptr && root->data > target) {
        return minDiffHelper(root->left, target, closest);
    } else if (root->right != nullptr && root->data < target) {
        return minDiffHelper(root->right, target, closest);
    } else {
        return closest;
    }
}

/*
Iterative approach also performs on average at O(log(n)) time and doesn't add any recursive calls to the call stack so we only consume constant O(1) space rather than O(log(n) space which we see when we recursively add to the call stack.

Both of the algorithms (recursive and iterative) at worst case have O(n) space or can be written as O(d) space where d = depth of the tree.
*/

// On average: O(log(n)) time and O(1) space
// Worst case: O(n) time and O(n) space
// where n = number of nodes in the tree

int minDiffHelper(Node *root, int target, int closest);

int minDiff(Node *root, int target) {
    return minDiffHelper(root, target, root->data);
}

int minDiffHelper(Node *root, int target, int closest) {
    Node *current = root;
    while (current != nullptr) {
        if (abs(target-closest) > abs(target-current->data)) {
            closest = current->data;
        }
        if (current->left != nullptr && current->data > target) {
            current = current->left;
        } else if (current->right != nullptr && current->data < target) {
            current = current->right;
        } else break;
    }
    return closest;
}