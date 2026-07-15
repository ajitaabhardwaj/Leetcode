import math
class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        e = 2
        o = 1
        sume, sumo = 0,0
        while n>0:
            sume += e
            e+=2
            sumo += o
            o+=2
            n-=1
       
        a = sume
        b = sumo

        while a>0 or b>0:
            if a > b:
                rem = a%b
                if rem == 0:
                    return b
                a = rem
            else:
                rem = b%a
                if rem == 0:
                    return a
                b = rem
          
