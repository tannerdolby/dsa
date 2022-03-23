#include <iostream>
#include "binary-search.h"
#include "singly-linked-list.h"
#include "binary-search-tree.h"

int main() {
    // Binary Search Examples
    int arr[] = {1,4,9,13,25,32,61,100};
    char carr[] = {'a','b','c','e','t','u','v','y'};

    int arrSize = sizeof(arr) / sizeof(arr[0]);
    vector<int> ve;
    vector<char> ce;

    for (int i=0; i < arrSize; i++) ve.push_back(arr[i]);
    for (int i=0; i < sizeof(carr) / sizeof(carr[0]); i++) ce.push_back(carr[i]);

    for (int v : ve) {
        cout << v << " ";
    }
    cout << endl;

    // vector<int> input
    cout << "Binary search for target 32: " << endl;
    int targetIdxOne = binarySearchRecursive(ve, 32);
    cout << "Found at index: " << targetIdxOne << endl;
    cout << "arr[" << targetIdxOne << "] = " << arr[targetIdxOne] << endl;

    // vector<char> input
    cout << "Binary search for target 'e': " << endl;
    int targetIdxFour = binarySearchIterative(ce, 'e');
    cout << "Found at index: " << targetIdxFour << endl;
    cout << "arr[" << targetIdxFour << "] = " << carr[targetIdxFour] << endl;

    // int[] input
    int targetIdxTwo = binarySearchRecursiveTwo<int, 8>(arr, 13);
    cout << "Binary search for target 13: " << endl;
    cout << "Found at index: " << targetIdxTwo << endl;
    cout << "arr[" << targetIdxTwo << "] = " << arr[targetIdxTwo] << endl;

    // char[] input
    int targetIdxThree = binarySearchRecursiveTwo<char, 8>(carr, 'u');
    cout << "Binary search for target 'u': " << endl;
    cout << "Found at index: " << targetIdxThree << endl;
    cout << "arr[" << targetIdxThree << "] = " << carr[targetIdxThree] << endl;

    // Singly Linked List demo
	LinkedList *list = new LinkedList(2);
	cout << "List Size: 1, Current head: " << list->get(0) << endl;

	cout << "inserting 5 nodes into the list" << endl;
	int vec[5] = {3,4,6,8, 9};
	for (int i=0; i < sizeof(vec) / sizeof(vec[0]); i++) {
		list->addAtTail(vec[i]);
	}

	cout << "list:" << endl;
	list->printList();

	cout << "length: " << list->iterativeGetLength() << endl;
	cout << "length: " << list->recursiveGetLength(list->head) << endl;

	cout << "is length even: " << list->iterativeIsLengthEven() << endl;
	cout << "is length even: " << list->recursiveIsLengthEven() << endl;

	cout << "Reversed: " << endl;
	ListNode* rev = list->iterativeReverse();
	list->printList();

    BinaryTree bt;
	Node *root = NULL;

	// 3 5 2 1 4 6 7
	int treeOne[] = {3, 5, 2, 1, 4, 6, 7 };
	// tree 1 - longest root-to-leaf path is 4 nodes connected by 3 edges, the tree tree height is 3
	/*
	       3
             /  \
            2    5
           /    /  \
          1    4    6
           	     \
	               7
	*/

	// iterate the integer array and insert nodes into tree
	for (int i = 0; i < sizeof(treeOne) / sizeof(treeOne[0]); i++) {
		root = bt.insert(root, treeOne[i]);
	}

	// Level Order Traversal (traverse the tree level by level going from leftmost node to right
	std::cout << "Level Order Traversal" << std::endl;
	bt.levelOrder(root);
	std::cout << std::endl;
  	// 3 2 5 1 4 6 7 

	// Max Height of Binary Tree
	std::cout << "Tree Height: " << bt.height(root) << std::endl;
  	// 3

	// tree 2
	Node *temp;
	BinaryTree bst;
	// 4 2 6 1 3 5 7
	int treeTwo[] = {4,2,6,1,3,5,7};
  
	for (int i = 0; i < sizeof(treeTwo) / sizeof(treeTwo[0]); i++) {
		temp = bst.insert(temp, treeTwo[i]);
	}
  
	std::cout << "Level order traversal: " << std::endl;
	bst.levelOrder(temp);
	std::cout << std::endl;
  	// 4 2 6 1 3 5 7 
  
	std::cout << "Tree Height: " << bst.height(temp) << std::endl;
  	// 2

    return 0;
}