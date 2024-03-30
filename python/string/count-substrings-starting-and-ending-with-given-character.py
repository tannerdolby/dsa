class Solution:
    def countSubstrings(self, s: str, c: str) -> int:
        # count the number of possible subarrays
        # that meet s[i] == c and s[j] == c
        # we count the occurrences of `c` in `s`
        # and that represents the length n we want
        # to use to calculate the number of subarrays
        # n * (n+1) / 2
        count = s.count(c)
        # input: s = "abada", c = "a"
        # first iteration
        # 3 occurrences of 'a' in `s`
        # 3 * (3+1) // 2 -> 3 * 4 // 2 -> 12 // 2 = 6
        return count * (count+1) // 2