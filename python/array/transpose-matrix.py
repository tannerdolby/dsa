# O(n * m) time and O(n * m) space - where
# n is the number of columns (width) and
# m is the number of rows (height)
def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
    m = len(matrix)
    n = len(matrix[0])
    transposed = [[] for _ in range(n)]
    for col in range(0, n):
        for row in range(0, m):
            transposed[col].append(matrix[row][col])
    return transposed