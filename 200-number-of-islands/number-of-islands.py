class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m = len(grid)-1
        n = len(grid[0])-1
        seen = [[False for _ in range(n+1)] for _ in range(m+1)]
        ans = 0

        def island(i, j, m, n):
            if seen[i][j] == True:
                return
            else:
                seen[i][j] = True

            if grid[i][j] == '0':
                return

            if i+1<=m:
                island(i+1, j, m, n)
            if i-1>=0:
                island(i-1, j, m, n)
            if j+1<=n:
                island(i, j+1, m, n)
            if j-1>=0:
                island(i, j-1, m, n)
            return 1

        i, j = 0,0
        for i in range(m+1):
            for j in range(n+1):
                if seen[i][j] == False and grid[i][j] == '1':
                    ans+=1
                    island(i, j, m, n)

        return ans

