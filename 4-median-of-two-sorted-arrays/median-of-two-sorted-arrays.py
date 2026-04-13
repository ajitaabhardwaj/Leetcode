class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        i, j = 0,0
        arr = []
        while i<len(nums1) and j<len(nums2):
            if nums1[i] < nums2[j]:
                arr.append(nums1[i])
                i+=1
            else:
                arr.append(nums2[j])
                j+=1

        while i<len(nums1):
            arr.append(nums1[i])
            i+=1

        while j<len(nums2):
            arr.append(nums2[j])
            j+=1

        mid = int(len(arr)/2)
        if len(arr)%2 == 0:
            return float((arr[mid-1] + arr[mid])/2)
        else:
            return float(arr[mid])
        