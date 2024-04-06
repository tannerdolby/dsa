class Solution:
    # O(n) time | O(1) space
    def fib(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1
        
        a = 0
        b = 1

        for i in range(2, n+1):
            nthFib = b + a
            a = b
            b = nthFib
        
        return b

    # O(n) time and O(n) space
    def fib(self, n: int) -> int:
        memo = {0: 0, 1: 1}
        return self.fibHelper(n, memo)

    def fibHelper(self, n: int, memo: dict) -> int:
        if n not in memo:
            memo[n] = self.fibHelper(n-1, memo) + self.fibHelper(n-2, memo)
        
        return memo[n]

    # O(2^n) time and O(d) space
    def fib(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1
        
        return self.fib(n-1) + self.fib(n-2)