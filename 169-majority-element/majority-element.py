class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 1
        i = 1
        nums.sort()
        while i<len(nums):
            if nums[i] == nums[i-1]:
                count+=1
            else:
                count=1
            if count > len(nums)/2:
                return nums[i]
            i+=1
        return nums[0]