class Solution:
    # O(n) time | O(n) space
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        result = []
        i = 0
        while i < len(nums):
            if 2*i+1 >= len(nums):
                break
            [freq, val] = nums[2*i], nums[2*i+1]
            result.extend([val] * freq)
            i += 1
        return result