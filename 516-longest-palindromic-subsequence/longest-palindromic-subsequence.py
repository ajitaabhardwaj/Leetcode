class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:

        text1 = s
        text2 = s[::-1]
        n = len(text1)
        m = len(text2)
        dp = [[0] * m for _ in range(n)]
        ans = 0
        for i in range(n):
            for j in range(m):
                if text1[i] == text2[j]:
                    if i == 0 or j == 0:
                        dp[i][j] = 1
                    else:
                        dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
                
                ans = max(ans, dp[i][j])
        return ans
        

            

