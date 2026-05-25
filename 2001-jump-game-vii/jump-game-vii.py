class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        i, j =0,1
        dp = [1]*len(s)
        dp[0] = 0
        psum = 0
        if s[len(s)-1] == '1':
            return False
        while j<=len(s)-1:
            if s[j] == '0':
                i = j - minJump
                while i>=0 and i >= j-maxJump:
                    if dp[i] == 0:
                        dp[j] = 0
                        break
                    i-=1

            psum = psum + dp[j]
            if j>= maxJump:
                psum = psum - dp[j-maxJump-1]
            if psum >= maxJump:
                return False

            j+=1

        if dp[-1] == 0:
            return True
        return False
