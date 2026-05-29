class Solution:
    def minElement(self, nums: List[int]) -> int:
        ans = 1000000
        for num in nums:
            digsum = 0

            while num>0:
                n = num%10
                num = num//10
                digsum += n
                if digsum > ans:
                    break
            ans = min(ans, digsum)

        return ans
            



        