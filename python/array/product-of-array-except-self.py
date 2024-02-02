class Solution:

    # Brute force (TLE)
    # O(n^2) time and O(n) space
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = [0] * len(nums)
        for i in range(0, len(nums)):
            product = 1
            for j in range(0, len(nums)):
                if i == j:
                   continue
                product *= nums[j]
            res[i] = product
        return res