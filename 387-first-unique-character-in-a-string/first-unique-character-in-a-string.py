class Solution:
    def firstUniqChar(self, s: str) -> int:
        map = {}
        st = ()
        for i in s:
            if i not in map:
                map[i] =1
            else:
                map[i] +=1
        
        for i in s:
            if map[i] ==1:
                return s.index(i)
        return -1