#
# [231] Power of Two
#
# https://leetcode.com/problems/power-of-two
#
# Easy (39.77%)
# Total Accepted:    130355
# Total Submissions: 327708
# Testcase Example:  '1'
#
# 
# Given an integer, write a function to determine if it is a power of two.
# 
# 
# Credits:Special thanks to @jianchao.li.fighter for adding this problem and
# creating all test cases.
#
class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n == 0: return False
        while(n % 2 == 0):
            n /= 2

        return n == 1
