class Solution:
    # O(n * n log(n)) time and O(n) space
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = {}
        for i in range(0, len(strs)):
            word = strs[i]
            chars = "".join(sorted(word))
            if chars not in anagrams:
                anagrams[chars] = []
            anagrams[chars].append(word)
        return anagrams.values()