class Solution:
    # O(n) time | O(1) space
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        time = 0
        for i in range(0, len(tickets)):
            if i <= k:
                time += min(tickets[i], tickets[k])
            else:
                time += min(tickets[i], tickets[k] - 1)
        return time
 
    # brute force
    # O(sum(tickets)) time | O(1) space
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        time = 0
        while tickets[k] != 0:
            for i in range(0, len(tickets)):
                if tickets[k] == 0:
                    return time
                if tickets[i] > 0:
                    tickets[i] -= 1
                    time += 1
        return time