class Solution:
    # O(n) time and O(n) space
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        intersected = set()
        for i in range(0, len(nums1)):
            if nums1[i] in nums2:
                intersected.add(nums1[i])
        return list(intersected)