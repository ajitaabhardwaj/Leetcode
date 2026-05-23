class Solution:
    def check(self, nums: List[int]) -> bool:
        i = 0
        flag = 0
        while i< len(nums)-1:
            if nums[i+1] < nums[i]:
                if nums[len(nums)-1] > nums[0]:
                    return False
                flag+=1
            
            if flag > 1:
                return False
            i+=1
            
        return True
        