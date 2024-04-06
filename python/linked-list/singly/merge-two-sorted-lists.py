# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    # O(n + m) time  | O(n + m) space
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        listOne = list1
        listTwo = list2
        sentinel = ListNode(-1)
        curr = sentinel

        while listOne and listTwo:
            if listOne.val <= listTwo.val:
                curr.next = listOne
                listOne = listOne.next
            else:
                curr.next = listTwo
                listTwo = listTwo.next
            curr = curr.next
        
        curr.next = listOne if listOne else listTwo

        return sentinel.next