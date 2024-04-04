class Solution:
    # O(n) time and O(n) space
    def sortedSquares(self, nums: List[int]) -> List[int]:
        squares = [0 for _ in nums]
        left = 0
        right = len(nums)-1
        idx = len(nums)-1

        while left <= right:
            if abs(nums[left]) < abs(nums[right]):
                squares[idx] = nums[right] * nums[right]
                right -= 1
            else:
                squares[idx] = nums[left] * nums[left]
                left += 1
            idx -= 1
        return squares

    # O(n log(n)) time and O(1) space
    def sortedSquares(self, nums: List[int]) -> List[int]:
        # iterate the array and square each element
        # then sort the array
        for i in range(0, len(nums)):
            nums[i] = nums[i] * nums[i]
        nums.sort()
        return nums
        