class Solution:
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
        