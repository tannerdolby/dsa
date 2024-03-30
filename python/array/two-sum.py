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

    # if we only want to find the values that sum
    # to target sum instead of indices we can do it in constant space
    # O(n log(n)) time and O(1) space
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums.sort()
        left = 0
        right = len(nums)-1
        while left < right:
            pairSum = nums[left] + nums[right]
            if pairSum == target:
                return [nums[left], nums[right]]
            elif pairSum < target:
                left += 1
            else:
                right -= 1
        return []

    # O(n^2) time and O(1) space
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(0, len(nums)):
            for j in range(i+1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]
        return [-1, -1]