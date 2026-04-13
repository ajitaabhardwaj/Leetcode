class Solution:
    def maxSubArray(self, nums: List[int]) -> int:

        dp = [ 0 for _ in range(len(nums))]
        for i, x in enumerate(nums):
            if i==0:
                dp[0] = x
                continue
            dp[i] = max(x, dp[i-1]+x)
        
        return max(dp)
