class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        results = 1.0
        if n == 0:
            return 1.0
        if n < 0:
            return 1.0 / self.myPow(x, -n)
        while n > 0:
            if n % 2 == 1:
                results = results * x
            n = n / 2
            x = x * x
        return results