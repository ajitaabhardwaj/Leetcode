class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        dict = {}
        start = 0
        end = 0
        ans = 0
        while end<=len(s)-1:
            if s[end] in dict and start<=end:
                start = max(start, dict[s[end]]+1)

            dict[s[end]] = end
            ans = max(ans, end-start+1)
            end+=1

        return ans
                
            


                

                
        