class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        sum = 0
        template = {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}
        if len(s) == 1:
            sum = template[s[0]]
        else:
            for ii in range(0,len(s)-1):
                if template[s[ii]] < template[s[ii+1]]:
                    sum = sum - template[s[ii]] 
                else:
                    sum = sum + template[s[ii]] 
            sum = sum + template[s[len(s)-1]]
        return sum