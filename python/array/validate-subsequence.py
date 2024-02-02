class Solution:
    # O(n) time and O(1) space
    def isSubsequence(self, s: str, t: str) -> bool:
        i = 0
        for j in range(0, len(t)):
            if i >= len(s):
                break
            if s[i] == t[j]:
                i += 1
        return i >= len(s)

    # O(n) time and O(1) space
    # def isSubsequence(self, s: str, t: str) -> bool:
    #     i = 0
    #     j = 0
        
    #     while i < len(s) and j < len(t):
    #         if s[i] == t[j]:
    #             i += 1
    #         j += 1
        
    #     return i >= len(s)