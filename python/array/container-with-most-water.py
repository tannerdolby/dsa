class Solution:
    # O(n) time and O(1) space
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height)-1
        area = 0
        while left < right:
            x = right-left
            y = min(height[left], height[right])
            area = max(area, x * y)
            if height[left] <= height[right]:
                left += 1
            else:
                right -= 1
        return area