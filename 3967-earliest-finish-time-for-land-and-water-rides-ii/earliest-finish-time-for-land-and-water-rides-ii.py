class Solution:
    def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int], waterStartTime: List[int], waterDuration: List[int]) -> int:

        minlend = float('inf')
        for i in range(len(landStartTime)):
            lend = landStartTime[i] + landDuration[i]
            if lend < minlend:
                minlend = lend

        minwend = float('inf')
        for i in range(len(waterStartTime)):
            wend = waterStartTime[i] + waterDuration[i]
            if wend < minwend:
                minwend = wend

        ans = float('inf')
        for i, wst in enumerate(waterStartTime):
            if wst < minlend:
                ridend = minlend + waterDuration[i]
                ans = min(ans, ridend)
            else:
                ridend = wst + waterDuration[i]
                ans = min(ans, ridend)      

        for i, lst in enumerate(landStartTime):
            if lst < minwend:
                ridend = minwend + landDuration[i]
                ans = min(ans, ridend)
            else:
                ridend = lst + landDuration[i]
                ans = min(ans, ridend)
        return ans
        


        






        