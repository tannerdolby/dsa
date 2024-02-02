class Solution:
    # O(n) time and O(n) space
    def containsDuplicate(self, nums: List[int]) -> bool:
        seen = set()
        for i in range(0, len(nums)):
            if nums[i] in seen:
                return True
            seen.add(nums[i])
        return False

    # O(n log(n)) time and O(1) space
    # def containsDuplicate(self, nums: List[int]) -> bool:
    #     nums.sort()
    #     for i in range(1, len(nums)):
    #         if nums[i] == nums[i-1]:
    #             return True
    #     return False