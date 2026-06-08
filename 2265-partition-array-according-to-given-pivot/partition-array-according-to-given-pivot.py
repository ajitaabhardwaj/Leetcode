from collections import deque
class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        count = 0
        countless = 0
        countmore = 0
        ql = deque()
        qr = deque()
        for n in nums:
            if n == pivot:
                count+=1
            elif n<pivot:
                countless+=1
                ql.append(n)
            else:
                qr.append(n)
        i = 0
        
        while ql:
            nums[i] = ql.popleft()
            i+=1
        while count > 0:
            nums[i] = pivot
            i+=1
            count-=1
        while qr:
            nums[i] = qr.popleft()
            i+=1
        return nums