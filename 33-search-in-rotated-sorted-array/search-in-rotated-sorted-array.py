class Solution:
    def search(self, nums: List[int], target: int) -> int:
        ans = -1
        def bs(start, end):
            nonlocal ans
            if end<start:
                return ans
            mid = (end+start)//2
            if target == nums[mid]:
                ans = mid
                return
            if target == nums[start]:
                ans = start
                return 
            
            if nums[start] <= nums[mid]:
                if target<=nums[mid] and target>=nums[start]:
                    bs(start, mid)
                else:
                    bs(mid+1, end)
            else:
                if target<=nums[end] and target>=nums[mid]:
                    bs(mid+1, end)
                else:
                    bs(start, mid)

        
        bs(0, len(nums)-1)
        return ans
        