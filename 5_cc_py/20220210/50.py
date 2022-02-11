from functools import lru_cache

class Solution:
    def myPow(self, x: float, n: int) -> float:
        x = 1/x if n < 0 else x
        n = abs(n)
        
        @lru_cache(maxsize=None)
        def powerPow(x: float, p):
            if p == 0:
                return 1.0
            half = powerPow(x, p//2)
            mult = half * half if p % 2 == 0 else half * half * x
            return mult
        
        return powerPow(x, n)
        