class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        there = {}
        i, j = 0, 0
        ans = 0
        for char in s:
            if char in there and j>i:
                i = max(there[char]+1, i)
                
            ans = max(ans, j-i+1)
            there[char] = j
            j+=1

        return ans
                

                
        