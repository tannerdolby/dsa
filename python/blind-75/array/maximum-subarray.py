class Solution:
    # O(n) time and O(1) space
    def maxSubArray(self, nums: List[int]) -> int:
        subarray = nums[0]
        largestSum = nums[0]
        for i in range(1, len(nums)):
            subarray = max(subarray + nums[i], nums[i])
            largestSum = max(largestSum, subarray)
        return largestSum