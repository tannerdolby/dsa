class Solution:
    # Using XOR
    # a ^ 0 = a
    # a ^ a = 0
    # a ^ b ^ b = a ^ 0 = a
    # O(n) time and O(1) space
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(0, len(nums)):
            n = n ^ i ^ nums[i]
        return n

    # given [3,0,1]
    # iteration 1
    # n = 3 ^ 0 ^ 3 = 3 ^ 3 = 0

    # iteration 2
    # n = 0 ^ 1 ^ 0 = 1 ^ 0 = 1

    # iteration 3
    # n = 1 ^ 2 ^ 1 = 1 ^ 1 ^ 2 = 0 ^ 2 = 2

    # Binary Search
    # 1. if we have to sort the input ourselves
    # O(n log(n)) time and O(1) space
    # 2. if the input is provided to the function sorted
    # O(log(n)) time and O(1) space
    def missingNumber(self, nums: List[int]) -> int:
        nums.sort()
        left = 0
        right = len(nums)-1

        while left <= right:
            mid = (left+right) // 2
            if nums[mid] == mid:
                left += 1
            else:
                right -= 1
        return left
