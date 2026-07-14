class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        n = len(matrix)
        m = len(matrix[0])
        ans = 0
        memo = [[-1] * m for _ in range(n)]

        for x in range(m):
            memo[-1][x] = int(matrix[-1][x])
            if memo[-1][x] == 1:
                ans = 1
        for x in range(n):
            memo[x][-1] = int(matrix[x][-1])
            if memo[x][-1] == 1:
                ans = 1
        print(memo)
        def dp(i , j):
            nonlocal ans
            if i<0 or j<0:
                return
            else:
                if memo[i][j] != -1 or memo[i+1][j+1] == -1 or memo[i][j+1] == -1 or memo[i+1][j] == -1:
                    return

                if matrix[i][j] == "0":
                    memo[i][j] = 0

                else:
                    memo[i][j] = 1 + min(int(memo[i+1][j+1]), int(memo[i][j+1]), int(memo[i+1][j]))

                ans = max(ans, memo[i][j])

            dp(i-1,j)
            dp(i, j-1)
            return
        

        dp(n-2, m-2)
        return ans*ans

    

                



        