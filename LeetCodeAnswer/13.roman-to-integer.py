#
# [13] Roman to Integer
#
# https://leetcode.com/problems/roman-to-integer
#
# Easy (44.81%)
# Total Accepted:    144031
# Total Submissions: 321367
# Testcase Example:  '"DCXXI"'
#
# Given a roman numeral, convert it to an integer.
# 
# Input is guaranteed to be within the range from 1 to 3999.
#
class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        num = 0
        template = {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}
        if len(s) == 1:
            num = template[s]
        else:
            for ii in range(len(s)-1):
                if template[s[ii+1]] > template[s[ii]]:
                    num = num - template[s[ii]]
                else:
                    num = num + template[s[ii]]
            num = num + template[s[len(s)-1]]
        return num


