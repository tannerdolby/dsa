class Solution:
    # O(n) time and O(1) space
    def lengthOfLastWord(self, s: str) -> int:
        length = 0
        for ch in reversed(s.rstrip()):
            if ch == " ":
                return length
            length += 1
        return length

    # O(n) time and O(n) space
    def lengthOfLastWord(self, s: str) -> int:
        words = s.strip().split(' ')
        return len(words[len(words)-1])