class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        ans = 0
        for num in range(num1, num2+1):
            s = str(num)
            i=1
            if len(s) <=2:
                continue
            while i<len(s)-1:
                if s[i] < s[i-1] and s[i] < s[i+1]:
                    ans += 1
                if s[i] > s[i-1] and s[i] > s[i+1]:
                    ans += 1
                i+=1
        return ans
            



        