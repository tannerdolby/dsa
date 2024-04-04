class Solution:
    # nested for loop takes O(n^2) time
    # and converting the list to set takes O(n) time
    # O(n^3) time and O(1) space - TLE
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        goodSubarrays = 0
        for i in range(0, len(nums)):
            for j in range(i, len(nums)):
                if len(set(nums[i:j+1])) == k:
                    goodSubarrays += 1
        return goodSubarrays