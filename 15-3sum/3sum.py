class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        target = 0
        ans = []
        nums.sort()

        for i in range(len(nums)-2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            new_target = target - nums[i]
            
            left = i+1
            right = len(nums)-1

            while left<right:
                if nums[left] + nums[right] == new_target:
                    ans.append([nums[i], nums[left], nums[right]])

                    left+=1
                    right-=1

                    while left<right and nums[left] == nums[left-1]:
                        left+=1

                    while left<right and nums[right] == nums[right+1]:
                        right-=1

                elif nums[left] + nums[right] < new_target:
                    left+=1
                else:
                    right-=1
        return ans

