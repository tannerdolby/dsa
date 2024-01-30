class Solution:
    # O(n) time and O(1) space
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        curr = head
        while curr is not None:
            nextNode = curr.next
            curr.next = prev
            prev = curr
            curr = nextNode
        return prev
    
    # Iteration 1
    # p c    n
    # N 1 -> 2 -> 3 -> 4 -> 5

    # curr.next = prev

    # p    c n
    # None <- 1 2 -> 3 -> 4 -> 5

    # prev = curr

    #         p 
    #         c n
    # None <- 1 2 -> 3 -> 4 -> 5

    # curr = nextNode

    # Iteration #2
    #         p c    n
    # None <- 1 2 -> 3 -> 4 -> 5

    # continue doing this until curr is None

    #                             p c
    # None <- 1 <- 2 <- 3 <- 4 <- 5 None

    # return prev pointer which is the new head of the
    # reversed linked list and started as the tail of the
    # original list
  