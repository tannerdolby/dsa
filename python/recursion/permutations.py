class Solution:
    # O(N! * N) time | O(N! * N) space
    def permute(self, nums: List[int]) -> List[List[int]]:
        permutations = []
        self.permuteHelper(0, nums, permutations)
        return permutations

    def permuteHelper(self, i: int, nums: List[int], permutations: List[List[int]]) -> List[List[int]]:
        if i == len(nums)-1:
            permutations.append(list(nums))
        else:
            for j in range(i, len(nums)):
                self.swap(nums, i, j)
                self.permuteHelper(i+1, nums, permutations)
                self.swap(nums, i, j)

    def swap(self, arr: List[int], i: int, j: int):
        temp = arr[i]
        arr[i] = arr[j]
        arr[j] = temp
    
    # Upper bound: O(N^2 * N!) time | O(N! * N) space
    # Average: O(N! * N) time | O(N! * N) space
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