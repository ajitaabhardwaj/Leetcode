class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix[0])
        m = len(matrix)
        memo = [[0 for _ in range(n)] for _ in range(m)]
        ans = float('inf')
        for j in range(0, len(matrix)):
            memo[0][j] = matrix[0][j]
            
        for i in range(1, len(matrix)):
            for j in range(0, len(matrix[0])):

                if j-1>=0:
                    a = memo[i-1][j-1]
                else:
                    a = float('inf')
                b = memo[i-1][j]

                if j+1<len(matrix[0]):
                    c = memo[i-1][j+1]
                else:
                    c = float('inf')
                memo[i][j] = matrix[i][j] + min(a, b, c)

        for j in range(0, len(matrix)):
            ans = min(ans, memo[-1][j])
                
        
        return ans
