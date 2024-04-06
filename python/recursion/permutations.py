class Solution:
    # O(n*n!) time | O(n*n!) space
    def permute(self, nums: List[int]) -> List[List[int]]:
        permutations = []
        self.permuteHelper(nums, [], permutations)
        return permutations

    def permuteHelper(self, nums: List[int], permutation: List[int], permutations: List[List[int]]) -> List[List[int]]:
        if not len(nums) and len(permutation):
            permutations.append(permutation)
        else:
            for i in range(0, len(nums)):
                newArr = nums[:i] + nums[i+1:]
                newPerm = permutation + [nums[i]]
                self.permuteHelper(newArr, newPerm, permutations)