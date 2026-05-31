class Solution:


    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0
        amt = amount
        dp = {}
        for i in coins:
            dp[i] = 1
        
        def check(amt):
            if amt in dp:
                return dp[amt]
            mini = 2**32
            for coin_i in coins:
                if amt>=coin_i:
                    mini = min(mini, check(coin_i) + check (amt-coin_i))
            dp[amt] = mini
            return dp[amt]

        
        ans = check(amount)
        if ans == 2**32:
            return -1
        else:
            return ans


        
        

        
        