class Solution:

    def minCostClimbingStairs(self, cost: List[int]) -> int:
        i = 0
        zero = 0
        first = 0
        curr = 0
        while i <= len(cost)-1:
            curr = cost[i] + min(zero,first)
            zero = first
            first = curr
            i+=1
        return min(zero, first)



        