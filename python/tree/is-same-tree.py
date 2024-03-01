# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # Recursive
    # O(n) time and O(d) space
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if p is None and q is None:
            return True
        if not p or not q:
            return False
        if p.val != q.val:
            return False

        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
        
    # Iterative
    # O(n) time and o(n) space
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        stack = [[p, q]]
        while len(stack) > 0:
            [a,b] = stack.pop()
            if not a and not b:
                continue
            if not a or not b:
                return False
            if a.val != b.val:
                return False
            else:
                stack.append([a.left, b.left])
                stack.append([a.right, b.right])
        return True
