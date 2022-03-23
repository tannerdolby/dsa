//============================================================================
// Name        : LinkedLists.cpp
// Author      : Tanner Dolby
// Version     : 0.0.1
// Copyright   : MIT License
// Description : Singly Linked List in C++.
//============================================================================

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {};
	ListNode(int x) : val(x), next(nullptr) {};
	ListNode(int x, ListNode *next) : val(x), next(nullptr) {};
};

class LinkedList {
public:
	ListNode *head;

	LinkedList() {
		head = nullptr;
	}

	LinkedList(int val) {
		head = new ListNode(val);
	}

	ListNode *getNode(int idx) {
		ListNode *curr = head;
		int i = 0;
		while (curr != nullptr && i != idx) {
			curr = curr->next;
		}
		return curr;
	}

	int get(int idx) {
		ListNode *curr = getNode(idx);
		if (curr == nullptr) return -1;
		return curr->val;
	}

	ListNode *getTail() {
		ListNode *curr = head;
		while (curr && curr->next) {
			curr = curr->next;
		}
		return curr;
	}

	void addAtHead(int val) {
		ListNode *newNode = new ListNode(val);
		newNode->next = head;
		head = newNode;
		return;
	}

	void addAtTail(int val) {
		if (head == nullptr) {
			addAtHead(val);
			return;
		}
		ListNode *newNode = new ListNode(val);
		ListNode *curr = getTail();
		curr->next = newNode;
	}

	void addAtIndex(int idx, int val) {
		if (idx == 0) {
			addAtHead(val);
			return;
		}

		ListNode *prev = getNode(idx-1);

		if (prev == nullptr) {
			return;
		}

		ListNode *newNode = new ListNode(val);
		ListNode *curr = prev->next;

		newNode->next = curr;
		prev->next = newNode;
	}

	// reverse list
	// O(n) time and O(1) space
	ListNode *iterativeReverse() {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		ListNode *prev = nullptr;
		ListNode *curr = head;
		while (curr != nullptr) {
			ListNode *next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
		return prev;
	}

	// recursive
	// O(n) time and O(n) space
	ListNode *recursiveReverse(ListNode *tempHead) {
		if (tempHead == nullptr || tempHead->next == nullptr) return tempHead;
		ListNode *curr = recursiveReverse(tempHead->next);
		tempHead->next->next = tempHead;
		tempHead->next = nullptr;
		head = curr;
		return curr;
	}

	// Iterative
	// O(n) time and O(1) space
	bool iterativeIsLengthEven() {
		ListNode *curr = head;
		int length = 0;
		while (curr != nullptr) {
			curr = curr->next;
			length++;
		}
		return length % 2 == 0 ? true : false;
	}

	// recursive
	// O(n) time and O(n) space
	bool recursiveIsLengthEven() {
		if (recursiveGetLength(head) % 2 == 0) {
			return true;
		}
		return false;
	}

	// O(n) time and O(1) space
	int iterativeGetLength() {
		ListNode *curr = head;
		int length = 0;
		while (curr != nullptr) {
			curr = curr->next;
			length++;
		}
		return length;
	}

	// pass in the head of linked list and recursively get the length
	// O(n) time and O(n) space
	int recursiveGetLength(ListNode *tempHead) {
		ListNode *curr = tempHead;
		if (curr == NULL || curr->next == NULL) {
			return 1;
		}
		return recursiveGetLength(curr->next) + 1;
	}

	void printList() {
		ListNode *curr = head;
		while (curr != NULL) {
			cout << curr->val << " ";
			curr = curr->next;
		}
		cout << endl;
	}
};