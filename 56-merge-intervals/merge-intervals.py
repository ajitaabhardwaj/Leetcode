class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        mp = {}
        intervals.sort(key = lambda x: x[0])
        for i in intervals: 
            flag = 0
            for key, value in mp.items():
                if i[0] >= key and i[0] <= value:
                    flag = 1
                    if i[1] >= value:
                        mp[key] = i[1]
                        break
            if flag==0:
                mp[i[0]] = i[1]
        
        ans = []
        
        for key, value in mp.items():
            ans.append([key, value])
        
        return ans

        