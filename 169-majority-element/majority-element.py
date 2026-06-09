class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        mp = {}
        for i in nums:
            if i not in mp:
                mp[i] = 1
            else:
                mp[i]+=1
            if mp[i] > len(nums)/2:
                return i
        return nums[0]