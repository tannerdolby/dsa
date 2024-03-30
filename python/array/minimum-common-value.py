class Solution:
    # O(n + m) time and O(1) space
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        i = 0
        j = 0
        minCommonVal = float('inf')
        while i < len(nums1) and j < len(nums2):
            if (nums1[i] < nums2[j]):
                i += 1
            elif nums1[i] > nums2[j]:
                j += 1
            else:
                minCommonVal = min(minCommonVal, nums1[i])
                i += 1
                j += 1
        if minCommonVal == float('inf'):
            return -1
        return minCommonVal
