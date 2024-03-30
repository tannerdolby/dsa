/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // O(N + N) = O(2N) = O(N) time
    // O(N) space for the string of length N
    bool isPalindrome(ListNode* head) {
        // could also use std::vector<int>
        string listValues = "";

        while (head != NULL) {
            listValues += head->val;
            head = head->next;
        }

        int left = 0;
        int right = listValues.length()-1;

        while (left < right) {
            if (listValues[left] != listValues[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};