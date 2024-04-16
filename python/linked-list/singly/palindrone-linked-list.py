# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    # O(n) time | O(1) space
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        # Find middle node
        middle = self.getMiddle(head)

        # Reverse right half of linked list starting
        # from the middle node
        rev = self.reverse(middle)

        # Compare reversed right half to original left half
        curr = head
        while rev:
            if rev.val != curr.val:
                return False
            rev = rev.next
            curr = curr.next
        
        return True
    
    # O(n) time | O(1) space
    def getMiddle(self, head: Optional[ListNode]) -> bool:
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow
    
    # O(n) time | O(1) space
    def reverse(self, head: Optional[ListNode]) -> ListNode:
        prev = None
        curr = head
        while curr:
            nextNode = curr.next
            curr.next = prev
            prev = curr
            curr = nextNode
        return prev