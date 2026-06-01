class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        cost.sort()
        cost = cost[::-1]
        ans = 0
        i = 1
        for c in cost:
            if i%3==0:
                i+=1
                continue
            ans = ans + c
            i+=1
        return ans

        