class Solution:
    def canJump(self, nums: List[int]) -> bool:
        i=len(nums)-2
        dp = [0]*i
        dest = len(nums)-1
        while i>=0:
            if dest-i <= nums[i]:
                dest = i
            i=i-1
        
        if dest == 0:
            return True
        return False
        

        
        