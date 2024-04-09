class Solution:
    # Iterative
    # O(n+m) time | O(n+m) space
    def mergeAlternately(self, word1: str, word2: str) -> str:
        i = 0
        n = len(word1)
        m = len(word2)
        merged = ""

        while i < n or i < m:
            if i < n:
                merged += word1[i]
            if i < m:
                merged += word2[i]
            i += 1
        return merged

    # Recursive
    # O(n + m) time | O(n + m) space
    def mergeAlternately(self, word1: str, word2: str) -> str:
        return self.mergeAlternatelyHelper(word1, word2, 0, 0, "")

    def mergeAlternatelyHelper(self, word1: str, word2: str, i, j, merged) -> str:
        if i < len(word1):
            merged += word1[i]
        if j < len(word2):
            merged += word2[j]
        if i >= len(word1) and j >= len(word2):
            return merged
        return self.mergeAlternatelyHelper(word1, word2, i+1, j+1, merged)
        