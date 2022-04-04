#include <iostream>
using namespace std;

// 1721. Swapping Nodes in a Linked List
// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {};

};

// O(n) time and O(1) space
ListNode* swapNodes(ListNode* head, int k) {
    if (head == NULL) return head;
    
    ListNode* p1 = head;
    ListNode* p2 = head;
    
    // move p1 k positions from head
    for (int i=0; i < k-1; i++) {
        p1 = p1->next;
    }
    
    ListNode* p3 = p1;

    // move p2 k positions from tail
    // and p3 will be at the tail
    while (p2 != NULL && p3->next != NULL) {
        p2 = p2->next;
        p3 = p3->next;
    }
    
    // Swap node values manually
    int nodeOneValue = p1->val;
    p1->val = p2->val;
    p2->val = nodeOneValue;
    
    // or perform the swap with built-int swap()
    // swap(p1->val, p2->val);
    
    return head;
}