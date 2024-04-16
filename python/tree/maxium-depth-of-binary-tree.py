class Solution:
    # Iterative using level order traversal (BFS)
    # O(n) time and O(n) space
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        stack = []
        stack.append(root)
        level = 0
        while len(stack):
            level += 1
            for i in range(0, len(stack)):
                top = stack.pop(0)
                if top.left:
                    stack.append(top.left)
                if top.right:
                    stack.append(top.right)
        return level
    
    # Recursive using DFS
    # O(n) time | O(d) space
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        leftSubtree = self.maxDepth(root.left)
        rightSubtree = self.maxDepth(root.right)
        return max(leftSubtree, rightSubtree) + 1