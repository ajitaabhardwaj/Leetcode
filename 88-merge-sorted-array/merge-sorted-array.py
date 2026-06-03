class Solution:
    def merge(self, num1: List[int], m: int, num2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i=len(num1)-1
        j=m-1
        k=n-1
        if n == 0:
            return
        while j>=0 and k>=0:
            if num1[j]>=num2[k]:
                num1[i] = num1[j]
                j-=1
            else:
                num1[i] = num2[k]
                k-=1
            i-=1
        while k>=0:
            num1[i] = num2[k]
            k-=1
            i-=1


            

