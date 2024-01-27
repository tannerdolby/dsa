class Solution:
    # O(n) time and O(n) space
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}
        for i in range(0, len(nums)):
            y = target - nums[i]
            if y in seen:
                return [i, seen[y]]
            seen[nums[i]] = i
        return [-1, -1]

    # O(n^2) time and O(1) space
    # def twoSum(self, nums: List[int], target: int) -> List[int]:
    #     for i in range(0, len(nums)):
    #         for j in range(i+1, len(nums)):
    #             if nums[i] + nums[j] == target:
    #                 return [i, j]
    #     return [-1, -1]