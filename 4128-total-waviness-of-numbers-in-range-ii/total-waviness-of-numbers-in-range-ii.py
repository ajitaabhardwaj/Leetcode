from functools import lru_cache

class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        
        def count_upto(n: int) -> int:
            if n <= 0:
                return 0
            
            digits = list(map(int, str(n)))
            m = len(digits)
            
            @lru_cache(None)
            def dfs(pos, prev2, prev1, started, tight):
                if pos == m:
                    return (1, 0) if started else (0, 0)
                
                limit = digits[pos] if tight else 9
                
                total_count = 0
                total_wave = 0
                
                for d in range(limit + 1):
                    new_tight = tight and (d == limit)
                    
                    if not started and d == 0:
                        child_count, child_wave = dfs(
                            pos + 1,
                            10,
                            10,
                            False,
                            new_tight
                        )
                        total_count += child_count
                        total_wave += child_wave
                    else:
                        add = 0
                        
                        if started and prev2 != 10:
                            if prev2 < prev1 > d:
                                add = 1
                            elif prev2 > prev1 < d:
                                add = 1
                        
                        child_count, child_wave = dfs(
                            pos + 1,
                            prev1 if started else 10,
                            d,
                            True,
                            new_tight
                        )
                        
                        total_count += child_count
                        total_wave += child_wave + add * child_count
                
                return total_count, total_wave
            
            return dfs(0, 10, 10, False, True)[1]
        
        return count_upto(num2) - count_upto(num1 - 1)