#include <iostream>
#include "binary-search.h"
#include "singly-linked-list.h"

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

    return 0;
}