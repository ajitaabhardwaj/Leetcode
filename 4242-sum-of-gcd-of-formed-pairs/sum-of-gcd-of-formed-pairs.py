import math
class Solution:
    def gcdSum(self, nums: list[int]) -> int: 
        prefix = []
        maxi = 0
        for n in nums:
            maxi = max(maxi, n)
            gcdi = math.gcd(maxi, n)
            prefix.append(gcdi)
        ans = 0
        n = len(prefix)
        prefix.sort()
        for i in range(0, (len(prefix)//2)):
            pairgcd = math.gcd(prefix[i], prefix[n-1-i])
            ans += pairgcd
        return ans
        