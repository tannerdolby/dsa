class Solution:
    # O(n log(n)) time and O(1) space
    def sortedSquares(self, nums: List[int]) -> List[int]:
        # iterate the array and square each element
        # then sort the array
        for i in range(0, len(nums)):
            nums[i] = nums[i] * nums[i]
        nums.sort()
        return nums
        