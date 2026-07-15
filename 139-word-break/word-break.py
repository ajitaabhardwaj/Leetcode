class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wd = {}
        for w in wordDict:
           wd[w] = 1

        memo = set()
        memo.add(0)
        def valid(memo, i):
            if i == len(s)+1:
                if i-1 in memo:
                    return True
                else:
                    return False
            for j in memo:
                if s[j:i] in wordDict:
                    memo.add(i)
                    break
            return valid(memo, i+1)
        
        return valid(memo, 1)
        
